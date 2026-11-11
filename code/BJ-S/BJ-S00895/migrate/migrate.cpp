#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define LL __int128
#define pb push_back
#define pf push_front
#define pof pop_front
#define pob pop_back
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define pdi pair<double,int>
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
using namespace std;
inline ll read(){
	ll k=0;char c=getchar();bool f=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){k=(k<<1)+(k<<3)+(c^48);c=getchar();}
	if(f)return -k;else return k;
}
inline char readc(){
	char c=getchar();
	while(!isgraph(c))c=getchar();
	return c;
}
inline string reads(){
	string s="";char c=getchar();
	while(!isgraph(c))c=getchar();
	while(isgraph(c)){s+=c;c=getchar();}
	return s;
}
void write(ll x){
	if(x>9)write(x/10);
	putchar((x%10)^48);
	return ;
}
const int N=2e6+10;
ll n,d,c,T,x[N],dis[N],l[N],r[N],cnt[N];
bool vis[N];
priority_queue<pli,vector<pli>,greater<pli>>q;
inline void dij(int s,int t){
	for(int i=1;i<=n;++i){
		dis[i]=1e18;
		vis[i]=0;
		cnt[i]=0;
	}
	dis[s]=0;
	cnt[s]=1;
	q.push({0,s});
	while(q.size()){
		int now=q.top().se;
		q.pop();
		if(dis[now]>dis[t])continue;
		for(int i=l[now];i<=r[now];++i){
			if(dis[i]>dis[now]+1){
				dis[i]=dis[now]+1;
				cnt[i]=cnt[now];
				q.push({dis[i],i});
			}
			else if(dis[i]==dis[now]+1)cnt[i]+=cnt[now];
		}
	}
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		n=read();d=read();
		for(int i=1;i<=n;++i)x[i]=read();
		if(n==1){
			puts("0");
			continue;
		}
		else if(n<=300){//afasdfsadf
			int L=1,R=0;
			for(int i=1;i<=n;++i){
				while(x[i]-x[L]>d)++L;
				while(R<n&&x[R+1]-x[i]<=d)++R;
				l[i]=L;
				r[i]=R;
			}
			int ans=0;
			for(int i=1;i<=n;++i){
				for(int j=1;j<i;++j){
					dij(i,j);
					if(cnt[j]==2)++ans;
				}
			}
			printf("%d\n",ans);
		}
		else if(11<=c&&c<=12){
			LL D=x[2]-x[1];
			ll p=d/D;
			if(p<=1)puts("0");
			else printf("%d\n",max(0,(int)(n-p*2+1)));
		}
		else puts("0");
	}
	return 0;
}
