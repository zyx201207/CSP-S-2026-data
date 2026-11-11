#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){char ch=getchar();int f=1;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}ll x=0;while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}return x*f;}
inline void write(ll x){if(x<0){putchar('-');x=-x;}if(x>=10)write(x/10);putchar(x%10+'0');}
int c,T;
int n;
const int N=2e6+5;
ll d,a[N],ans;
int dis[N],f[N];
const ll inf=1e18;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read();d=read();
		for(int i=1;i<=n;i++)a[i]=read();
		ans=0;
		if(c<=10){
			for(int s=1;s<=n;s++){
				for(int i=s;i<=n;i++){
					dis[i]=1e9;f[i]=0;
				}
				dis[s]=0;
				for(int i=s,r=s+1;r<=n;i++){
					while(r<=n&&a[r]-a[i]<=d){
						dis[r]=dis[i]+1;
						r++;
					}
					if(r==i+1)break;
				}
//				cout<<s<<" :\n";
//				for(int i=1;i<=n;i++){
//					cout<<dis[i]<<" ";
//				}
//				cout<<"\n";
				f[s]=1;
				for(int i=s+1;i<=n;i++){
					if(dis[i]==1e9)break;
					int cnt=0,p1=0,p2=0;
					for(int j=i-1;j>=s;j--){
						if(a[i]-a[j]>d)break;
						if(dis[j]+1!=dis[i])continue;
						cnt++;
						if(cnt>2)break;
						if(!p1)p1=j;
						else p2=j;
					}
					if(cnt>2){
						f[i]=cnt;
					}
					else if(cnt==2){
						if(f[p1]==1&&f[p2]==1){
							ans++;
						}
						f[i]=f[p1]+f[p2];
					}
					else{
						if(f[p1]==2)ans++;
						f[i]=f[p1];
					}
//					cout<<f[i]<<" ";
				}
//				cout<<"\n";
			}
		}
		else if(11<=c&&c<=12){
			if(n>1){
				ll g=a[2]-a[1];
				if(d>g){
					ll l=(d-1)/g;
					ll r=l+1;
					if(l+r-1<=n)
					ans=n-(l+r-1)+1;
//					cout<<2*r<<"!\n";
				}
			}
			
		}
		write(ans);puts("");
	}
	return 0;
}
/*
0 1
5 3
-3 0 2 3 4
*/
