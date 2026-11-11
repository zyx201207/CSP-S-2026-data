#include<bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout)
#define ll long long
const int N=2e6+10;
ll a[N],nxt[N],len[N],oeea[N],siz[N],siz2[N],kkk[N];
int T,c,n;
ll d,ans;
int fa[N];
int find_max(int i){
	return upper_bound(a+1,a+1+n,a[i]+d)-a-1;
}
void init(){
	for(int i=1;i<=n;i++){
		siz[i]=1;
		siz2[i]=0;
		oeea[i]=0;
		kkk[i]=1;
		fa[i]=i;
	}
	ans=0;
}
int find_f(int x){
	return x==fa[x]?x:fa[x]=find_f(fa[x]);
}
void Merge(int x,int y){
	x=find_f(x);
	y=find_f(y);
	if(x!=y){
		fa[x]=y;
		len[y]+=len[x];
		siz[y]+=siz[x];
	}
}
int main(){
	FILE("migrate"); 
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>T;
	nxt[0]=1;
	while(T--){
		cin>>n>>d;
		init();
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			nxt[i]=find_max(i);
			len[i]=nxt[i]-nxt[i-1];
		}
		for(int i=n;i>0;i--){
			int lst=nxt[i];
			if(lst==i) continue;
			if(lst==i+1||nxt[lst]>nxt[lst-1]){
				oeea[i]=siz[find_f(lst)];
				Merge(i,lst);
			}
			if(nxt[lst]==lst) continue;
			if(lst>=i+2){
				siz2[i]=nxt[lst-1]-nxt[lst-2];
			}
		}
		for(int i=1;i<=n;i++){
			if(siz2[i]) ans+=(siz[find_f(i)]-oeea[i])*(siz2[i]+len[find_f(nxt[nxt[i]])]);
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
