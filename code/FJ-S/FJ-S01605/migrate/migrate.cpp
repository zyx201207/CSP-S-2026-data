#include<bits/stdc++.h>
#define mk mkae_pair
#define fir first
#define sec second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
inline ll read(){char ch=getchar();ll xxx=0,yyy=1;
while(ch<'0'||ch>'9'){if(ch=='-')yyy*=-1;ch=getchar();}
while(ch>='0'&&ch<='9'){xxx=(xxx<<1)+(xxx<<3)+(ch^48);ch=getchar();}
return xxx*yyy;
}
void write(ll xxx){
	if(xxx>=10)write(xxx/10);
	putchar('0'+xxx%10);
}
const int maxn=2000005;

int n;
int pos[maxn],dis[5005][5005],dp[5005][5005],lst[maxn],nxt[maxn];
ll x[maxn],d;

void slv(){
	ll dd=x[2]-x[1];
	ll tmp=d/dd;
	if(tmp==0||tmp==1){
		putchar('0');putchar('\n');
		return ;
	}
	ll ans=n-2*tmp+1;
	write(max(0LL,ans));
	putchar('\n');
//	cout<<dd<<' '<<d<<endl;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio();cin.tie(0);cout.tie(0);
	int C,T;cin>>C>>T;
	while(T--){
		n=read();d=read();
		for(int i=1;i<=n;i++)lst[i]=n+1;
		for(int i=1;i<=n;i++){
			x[i]=read();
		}
		if(n==1){
			putchar('0');
			putchar('\n');
			continue;
		}
		if(C==11||C==12){
			slv();continue;
		}
		for(int i=1,r=0;i<=n;i++){
			while(r+1<=n&&x[r+1]-x[i]<=d)++r;
			nxt[i]=r;lst[r]=min(lst[r],i);
		}
		for(int i=n-1;i>=1;i--)lst[i]=min(lst[i],lst[i+1]);
//		for(int i=1;i<=n;i++)cout<<lst[i]<<' ';cout<<endl;
//		for(int i=1;i<=n;i++)cout<<nxt[i]<<' ';cout<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)dp[i][j]=0;
			pos[0]=i;dis[i][i]=0;
			int mx=n;
			for(int j=i+1,cur=0;j<=n;j++){
				if(x[j]-x[pos[cur]]<=d){
					dis[i][j]=cur+1;
				}else{
					pos[++cur]=j-1;
					if(x[j]-x[j-1]<=d)dis[i][j]=cur+1;
					else {
						mx=j-1;break;
					}
				}
			}
//			for(int j=0;j<=n;j++)cout<<pos[j]<<' ';cout<<endl;
			dp[i][i]=1;
			for(int j=i+1;j<=mx;j++){
//				cout<<"upd"<<i<<' '<<j<<' '<<pos[dis[i][j]-1]<<' '<<lst[j]-1<<endl;
				dp[i][j]=min(3,dp[i][pos[dis[i][j]-1]]-dp[i][lst[j]-1]);
				dp[i][j]+=dp[i][j-1];
			}
			for(int j=mx;j>i;j--)dp[i][j]-=dp[i][j-1];
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
//				cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
				ans+=(dp[i][j]==2);
			}
		}
		write(ans);putchar('\n');
	}
	return 0;
}

/*

0 1
8 3
0 1 2 4 8 10 11 13

*/
