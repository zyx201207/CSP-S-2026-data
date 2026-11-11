#include<bits/stdc++.h>
using namespace std;
int a[1100000];
int x[1100000];
int n,m;
long long dfs(long long ans,long long mx,int j){
	if(j==m){
		return ans;
	}
	for(int i=1;i<=n;i++){
		if(x[i]==1)continue;
		x[i]=1;
		mx=max(mx,dfs((ans&a[i]),0,j+1));
		x[i]=0;
	}
	return mx;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int mm=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++){
			if(a[i]+1==int(pow(2,j))){
				mm++;
				break;
			}
		}
	}
	sort(a+1,a+1+n,cmp);
	if(mm==n){
		cout<<a[m];
		return 0;
	}
	cout<<dfs(int(pow(2,31)-1),0,0);
	return 0;
}
