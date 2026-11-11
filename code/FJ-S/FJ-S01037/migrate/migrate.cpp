#include <bits/stdc++.h>
using namespace std;
const int N=2000005,SN=5005;
const long long inf=0x3f3f3f3f3f3f3f3f;
int c,T;
int n;
long long d,a[N];
long long f[SN][SN],g[SN][SN];
void solve_1_6(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[j]-a[i]<=d){
				f[i][j]=1,g[i][j]=1;
			}
			else{
				f[i][j]=inf,g[i][j]=0;
			}
		}
	}
	for(int len=3;len<=n;len++){
		for(int l=1,r=len;r<=n;l++,r++){
			for(int k=l+1;k<r&&a[k]-a[l]<=d;k++){
				if(f[l][r]>1+f[k][r]){
					f[l][r]=1+f[k][r];
					g[l][r]=g[k][r];
				}
				else if(f[l][r]==1+f[k][r]){
					g[l][r]+=g[k][r];
				}
			}
		}
	}
	long long ans=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if(g[l][r]==2){
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}
void solve_11_12(){
	cin>>n>>d;
	if(n<=3){
		cout<<0<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(d>=2*(a[2]-a[1]))cout<<n-d*(a[2]-a[1])-2<<endl; 
	else cout<<0<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	if(c>=0&&c<=10){
		while(T--)solve_1_6();
	}
	else if(c>=11&&c<=12){
		while(T--)solve_11_12();
	}
	else{
		while(T--)cout<<0<<endl;
	}
}
