#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],vis[N],ans,num[5];
bool pdA=true,pdB=true,pdC=true;
void dfs(int dep,int sum){
	if(dep==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(dep+1,sum&a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]%2==0)
			pdA=false;
		if(a[i]>=4)
			pdC=false;
	}
	if(n<=2000){
		for(int i=1;i<=n;i++){
			vis[i]=1;
			dfs(1,a[i]);
			vis[i]=0;
		}
		cout<<ans<<endl;
	}
	else{
		if(pdA){
			sort(a+1,a+n+1);
			cout<<a[n-m+1]<<endl;
		}
		else if(pdC){
			for(int i=1;i<=n;i++){
				num[a[i]]++;
			}
			if(m<=num[3])
				cout<<3;
			else if(m<=num[3]+num[2])
				cout<<2;
			else if(m<=num[3]+num[1])
				cout<<1;
			else
				cout<<0;
		}
	}
	return 0;
}
