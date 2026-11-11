#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
const int M=1e6+10;
const int K=15;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f*=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int c,t;
int n,d,a[N];
//int pos[N];
//inline int solve(int id){
//	int pos=id,p=1;
//	while(p){
//		if(pos+p>n){
//			p/=2;
//			continue;
//		}
//		if(abs(a[pos+p]-a[id])<=d){
//			pos+=p;
//			p*=2;
//		}else{
//			p/=2;
//		}
//	}
//	return pos;
//}
int dis[N],f[N];
void bfs(int s){
	queue<pair<int,pair<int,int> > > q;
	for(int i=1;i<=n;++i)dis[i]=INF,f[i]=0;
	dis[s]=0;
	q.push({s,{0,1}});
	while(!q.empty()){
		pair<int,pair<int,int> > cu=q.front();
		q.pop();
		int u=cu.first,dd=cu.second.first,c=cu.second.second;
		if(dis[u]<dd)continue;
//		cout<<u<<" "<<dd<<" "<<c<<endl;
		f[u]+=c;
		int nxt=u+1;
		while(1){
			if(nxt>n)break;
//			cout<<" v:"<<nxt<<" "<<abs(a[nxt]-a[u])<<endl;
//			cout<<" disv:"<<dis[nxt]<<endl;
			if(abs(a[nxt]-a[u])<=d){
				if(dis[nxt]>dis[u]+1){
					dis[nxt]=dis[u]+1;
					q.push({nxt,{dis[nxt],f[u]}});
//					cout<<"go!!"<<endl;
				}else if(dis[nxt]==dis[u]+1){
					f[nxt]+=c; 
//					cout<<"++"<<endl;
				}
				nxt++;
			}else{
				break;
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read(),d=read();
		for(int i=1;i<=n;++i){
			a[i]=read();
		}
		int cnt=0;
		for(int i=1;i<=n;++i){
//			cout<<i<<endl;
			bfs(i);
			for(int j=i+1;j<=n;++j){
//				cout<<f[j]<<" ";
				if(f[j]==2)cnt++;
			}
//			cout<<'\n';
		}
		write(cnt);
		putchar('\n');
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
6 3
1 3 4 6 9 11
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983

*/
/*
int ans=0;
		for(int u=1;u<=n;++u){
//			cout<<"u:"<<u<<endl;
			pos[u]=solve(u);
//			cout<<"pos:"<<pos[u]<<endl;
			int lst=pos[u];
			bool f=0;
			for(int v=pos[u]+1;v<=n;++v){
//				cout<<" v:"<<v<<endl;
				if(abs(a[lst-1]-a[v])<=d){
					if(f){
						break;
					}else{
						f=1;
						if(abs(a[lst-2]-a[v])<=d){
							break;
						}
						ans++;
					}
				}else{
					lst=v;
				}
			}
//			cout<<"ans:"<<ans<<endl<<endl;
		}
		cout<<ans<<'\n';
*/
