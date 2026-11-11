#include<bits/stdc++.h>
using namespace std;
const int N=2e3+10;
const __int128 INF=3e18;
typedef long long ll;
ll c,t;
ll n;
__int128 d;
__int128 a[N];
bool f;
__int128 dis[N][N];
__int128 cnt[N][N];
__int128 ans;
__int128 read(){
	__int128 f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c-'0');
		c=getchar();
	}
	return f*x;
}
void print(__int128 x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		n=read();
		d=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=2;i<=n;i++){if(i!=2&&a[i]-a[i-1]!=a[i-1]-a[i-2])f=1;}
		if(!f){
//			cout<<"j1\n\n";
			__int128 dd=0;
			__int128 h=a[n]-a[n-1];
//			cout<<dd<<"\n"<<h<<"\n";
			for(int i=1;i<=n;i++){
				dd+=h;
				if((dd>d)&&(dd%d!=0)&&(dd/d)<2){
					ans=(n-i);
//					cout<<i<<"\n";
//					print(d);cout<<" ";
//					print(dd);cout<<" ";
//					print(ans);cout<<" ";
//					cout<<"\n";
				}
			}
			print(ans);
			cout<<"\n";
		}
		else{
//			for(int i=1;i<=n;i++)print(a[i]),cout<<" ";
			for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dis[i][j]=INF;
			memset(cnt,0,sizeof(cnt));
			ans=0;
			for(int i=1;i<=n;i++)dis[i][i]=0;
			for(int i=1;i<=n;i++){
				for(int l=1;l+i-1<=n;l++){
					int r=l+i-1;
					if(a[r]-a[l]<=d){
						dis[l][r]=1;
						cnt[l][r]=1;
						continue;
					}
					for(int k=l;k<=r;k++){
						if(dis[l][k]+dis[k][r]==dis[l][r]){
							cnt[l][r]++;
						}
						if(dis[l][k]+dis[k][r]<dis[l][r]){
							dis[l][r]=dis[l][k]+dis[k][r];
							cnt[l][r]=1;
						}
					}
				}
			}
//			for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cout<<i<<" "<<j<<" "<<dis[i][j]<<"\n";
//			cout<<"\n\n";
//			for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cout<<i<<" "<<j<<" "<<cnt[i][j]<<"\n";
			for(int l=1;l<=n;l++){
				for(int r=l+1;r<=n;r++){
					if(cnt[l][r]==2)ans++;
				}
			}
			print(ans);
			cout<<"\n";
		}
	}
	return 0;
}
//__int128
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
