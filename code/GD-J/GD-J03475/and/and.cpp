#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll INF=0x3f3f3f3f;
int a[100000];
int n,k;
int ans=0;
int path[10000];
void dfs(int i,int b){
	if(i==n&&b==k){
int res=0;
bool ok=true;
		for(int i=0;i<n;i++){

			if(path[i]==1){
				if(ok){
					ok=false;
					res=a[i];
				}else{
					res&=a[i];
				}
			}
		}
		ans=max(ans,res);
	}
	if(k>0)path[i]=1;
	dfs(i+1,b+1);
	path[i]=0;
	dfs(i+1,b);
}
int main(){

//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}
//4 2 3 15 12 12

