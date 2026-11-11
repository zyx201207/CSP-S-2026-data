#include<bits/stdc++.h>
using namespace std;
char BEGIN;
namespace hwq{
	#define ll long long
	#define pb push_back
	char buf[1<<21],*_S,*_T;
	#define gc (_S==_T&&(_T=(_S=buf)+fread(buf,1,1<<21,stdin),_S==_T)?EOF:(*_S++))
	inline ll read(){ll x=0;bool f=0;char ch=gc;while(!isdigit(ch)&&ch!='-') ch=gc;if(ch=='-') f=1,ch=gc;while(isdigit(ch)) x=(x<<3)+(x<<1)+ch-48,ch=gc;return f?-x:x;}
	const int MAXN=1e6+5;
	int ci,ti;
	int n,K;
	vector<int>ed[MAXN];
	inline void add_ed(int u,int v){
		ed[u].pb(v),ed[v].pb(u);
	}
	int main(){
		ci=read(),ti=read();
		while(ti--){
			for(int i=1;i<=n;i++) ed[i].clear(),ed[i].shrink_to_fit();
			n=read(),K=read();
			for(int i=1;i<n;i++) add_ed(read(),read());
			
		}
		return 0;
	}
}
char END;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
#ifdef XYHQ
	printf("Memory : %lld MB\n",(&BEGIN-&END)>>20);
	freopen("1.in","r",stdin);
//	freopen("hub.in","r",stdin);
//	freopen("hub.out","w",stdout);
#else
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
#endif
	clock_t begin=clock();
	hwq::main();
	clock_t end=clock();
	cerr<<endl<<"Time : "<<((double)end-(double)begin)/1000.0<<" s"<<endl;
	return 0;
}
