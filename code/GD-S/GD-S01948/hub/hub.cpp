#include<bits/stdc++.h>
#define LL long long
#define P(i,s,t) for(int i=s;i<=t;++i)
#define S(i,s,t) for(int i=s;i>=t;--i)
using namespace std;
const int N=1e6+5;
vector<int>add[N];
int n,k,dep[N],maxx[N],siz[N],x,y,xx,z,l,r,rr,mid,mm;
int a[N],cnt,bz[N],tot,ans;
int st,en,o,oo;
void dfs(int u,int fa){
	if(dep[u]>x) x=dep[u],y=u;
	siz[u]=1;
	maxx[u]=dep[u];
	for(int v:add[u]) if(v!=fa)
		dep[v]=dep[u]+1,dfs(v,u),maxx[u]=max(maxx[u],maxx[v]),siz[u]+=siz[v];
}
void dfs1(int u,int fa){
	a[++cnt]=u;
	if(en==u){x=1; return ;}
	for(int v:add[u]) if(v!=fa){
		dfs1(v,u);
		if(x) return ;
	}
	cnt--;
}

void solve(){
	cin>>n>>k,cnt=0;
	P(i,2,n) cin>>x>>y,add[x].push_back(y),add[y].push_back(x);
	x=-1,dep[1]=1,dfs(1,0),st=y;
	x=-1,dep[st]=1,dfs(st,0),en=y;
	x=0,dfs1(st,0);
	oo=(cnt+1)>>1;
	o=a[oo],dep[o]=1,dfs(o,0);
	P(i,oo,cnt-1) siz[a[i]]-=siz[a[i+1]];
	S(i,oo,1) siz[a[i]]-=siz[a[i-1]];
	P(i,1,cnt){
		maxx[a[i]]=1;
		for(int v:add[a[i]]) if(v!=a[i+1]&&v!=a[i-1]){
			maxx[a[i]]=max(maxx[a[i]],maxx[v]);
		}
	}
	
	l=0,r=oo,ans=oo;
//	cout<<l<<' '<<r<<'\n';
	while(l<=r){
		mid=(l+r)>>1,tot=0;
		if(mid==0){
			if(k==n)ans=mid;
			break;
		}
		P(i,1,n){
			if(maxx[i]-dep[i]>=mid){
				bz[i]=2,tot++;
			}else bz[i]=0;
		}
		if(!bz[a[mid+1]]&&mid+1<=oo)
			bz[a[mid+1]]=2,tot++;
		if(!bz[a[cnt-mid]]&&cnt-mid>=oo)
			bz[a[cnt-mid]]=2,tot++;
		P(i,mid+1,cnt-mid) if(!bz[a[i]]) bz[i]=1,tot++;
		
		if(tot<=k){
			r=mid-1,ans=mid;
			continue;
		}else{
			tot-=k;
			x=mid+2,y=cnt-mid-1,z=0;
//			cout<<"+ "<<x<<' '<<y<<' '<<tot<<'\n';	
			P(ll,x,y-tot+1){
				z=1;
				rr=x+tot-1;
				mm=(ll+rr)/2;
				P(i,ll,mm){
					xx=a[i];
					if(bz[xx]==2||maxx[xx]-dep[xx]+i-ll+1>mid){
						z=0;
						break;
					}
				}
				if(z){
					P(i,mm+1,rr){
						xx=a[i];
						if(bz[xx]==2||maxx[xx]-dep[xx]+rr-i+1>mid){
							z=0;
							break;
						}
					}
				}
				if(z) break;
			}	
			if(z){
				r=mid-1,ans=mid;
				continue;
			}
		}
		l=mid+1;
	}
	cout<<ans<<'\n';
	P(i,1,cnt) a[i]=0;
	P(i,1,n) add[i].clear();
	
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int C,T;
	cin>>C>>T;
	while(T--) solve();
	
	
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
