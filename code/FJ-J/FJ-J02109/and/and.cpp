#include<bits/stdc++.h>
using namespace std;
vector<long long> a;
long long mx=-9999;
bool used[200002]={0};
int n,m;
void dfs(int x,int ceng){
	if(ceng>n){
		long long sum=0;
		bool flag=0;
		for(int i=0;i<=200001;i++){
			if(used[i]){
				if(!flag){
					sum=a[i];
					flag=1;
				}
				else{
					sum=sum&a[i];
				}
			}
		}
		mx=max(mx,sum);
		return;
	}
	for(int i=x;i<n;i++){
		used[i]=1;
		dfs(x+1,ceng+1);
		used[i]=0;
	}
}
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int ip;cin>>ip;a.push_back(ip);
	}	
	dfs(0,1);
	cout<<mx;
	return 0;
}
