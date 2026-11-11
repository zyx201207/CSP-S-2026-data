#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,ans,mn;
int n,d;
int x[N];
//int f=0;
void dfs(int sum,int l,int r){
	if(sum>mn)return;
	if(l==r){
		if(sum<mn){
			mn=sum;
			ans=1;
		}
		else if(sum==mn)ans++;
		return;
	}
	for(int i=l+1;i<=r;i++){
		if(x[i]-x[l]<=d){
			dfs(sum+1,i,r);
		}
		else break;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				mn=1e9;
				ans=0;
				dfs(0,i,j);
				if(ans==2){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
}
