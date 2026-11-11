#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x[355],f[355][355],d,p[355][355];
int solve(){
	int ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		f[i][j]=0;
		p[i][j]=1e15;	
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(abs(x[i]-x[j])<=d)
	f[i][j]=p[i][j]=1;	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int k=1;k<=n;k++)
	if(i!=j&&j!=k&&i!=k){
		if(p[i][j]==p[i][k]+p[k][j])f[i][j]+=f[i][k]*f[k][j];
		if(p[i][j]>p[i][k]+p[k][j]){
			p[i][j]=p[i][k]+p[k][j];
			f[i][j]=f[i][k]*f[k][j];
		}	
	}
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	if(f[i][j]==2)ans++;	
	return ans;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int C=0,T=0;
	cin>>C>>T;
	while(T){
		T--;
		cout<<solve()<<'\n';
	}
	return 0;
}
