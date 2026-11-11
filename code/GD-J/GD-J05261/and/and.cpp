#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],sum,maxx;
vector<int>vis;
int v1[100005],v2[100005],f;
bool l(int x){
	for(int i=0;i<vis.size();i++){
		if(vis[i]==x||v1[x]<=v2[x]){
			return 0;
		}
	}
	return 1;
}
void dfs(int x,int y){
 	sum=sum&x;
 	if(vis.size()==m){
	 	maxx=max(maxx,sum);
	}
 	for(int i=1;i<=n;i++){
 		if(vis.empty()) f=1;
 		if(l(a[i])&&vis.size()<m){
 			if(f==1){
 				sum=a[i];
 				f=0;
			}
 			v2[a[i]]++;
 			vis.push_back(a[i]);
 			dfs(a[i],sum);
 			sum=y;
 			v2[a[i]]--;
 			vis.pop_back();
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v1[a[i]]++;
	}
	dfs(0,0);
	cout<<maxx;
	return 0;
}
