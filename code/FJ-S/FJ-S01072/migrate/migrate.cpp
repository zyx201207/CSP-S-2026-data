#include<bits/stdc++.h>
#define ll long long
using namespace std;
void read(int &n){int x=0,f=1;char c=getchar();while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}n=x*f;}
void read(ll &n){ll x=0,f=1;char c=getchar();while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}n=x*f;}
const int N=305;
int c,t;
ll x[N],f[N][N],len[N][N],n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	read(c);read(t);
	while(t--){
		read(n);read(d);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)f[i][j]=0,len[i][j]=998244353;
		}
		for(int i=1;i<=n;i++)read(x[i]);
		for(int i=1;i<n;i++){
			int r=i+1;
			while(r<=n&&x[r]-x[i]<=d){
				len[i][r]=1;f[i][r]=1;
//				cout<<"Ö±´ï"<<i<<' '<<r<<endl;
				r++;
			}
		}
		for(int l=2;l<=n;l++){
			for(int i=1,r=i+l;r<=n;i++,r++){
				for(int k=i+1;k<r;k++){
					if(len[i][k]>1)continue; 
//					if(i==1&&r==5){
//						cout<<k<<' '<<len[i][k]<<' '<<len[k][r]<<' '<<f[i][k]<<' '<<f[k][r]<<endl;
//					}
					if(len[i][r]>len[i][k]+len[k][r]){
						len[i][r]=len[i][k]+len[k][r];
						f[i][r]=f[i][k]*f[k][r]%998244353;
					}else if(len[i][r]==len[i][k]+len[k][r]){
						f[i][r]+=f[i][k]*f[k][r]%998244353;
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
//				if(f[i][j]==2)cout<<i<<' '<<j<<endl;
				if(f[i][j]==2)ans++;
			}
		}
//		cout<<len[1][5]<<' '<<f[1][5]<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
