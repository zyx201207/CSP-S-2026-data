#include<bits/stdc++.h>
using namespace std;
char ch[1<<20],*P,*Q;
#define gc() (((P==Q&&(P=(Q=ch)+fread(ch,1,1<<20,stdin))),P==Q)?EOF:*Q++)
#define int long long
inline int read(){
	int res=0;bool sign=false;char c=gc();
	for(;!isdigit(c);c=gc()) if(c=='-') sign=true;
	for(;isdigit(c);c=gc()) res=res*10+c-'0';
	return sign?-res:res;
}
int c,t,n,k,h[1000005],dfn[1000005],tot,lg[1000005],sta[1000005],fg[1000005],tag[1000005];
vector<int>link[1000005];
struct ST{
	pair<int,int>num[1000005][21];
	int tot;
	void clear(){
		tot=0;
	}
	void insert(pair<int,int>x){
		num[++tot][0]=x;
	}
	void does(){
		for(int i=1;i<21;i++) for(int l=1;l+(1<<i)-1<=tot;l++) 
			num[l][i]=min(num[l][i-1],num[l+(1<<(i-1))][i-1]);
	}
	pair<int,int>query(int l,int r){
		int len=lg[r-l+1];
		return min(num[l][len],num[r-(1<<len)+1][len]);
	}
}s;
int lca(int u,int v){
	if(sta[u]>sta[v]) swap(u,v);
	return s.query(sta[u],sta[v]).second;
}
int dis(int u,int v){
	int w=lca(u,v);
	return h[u]+h[v]-2*h[w];
}
struct sets{
	set<int>s;
	int num=0;
	void clear(){
		s.clear(),num=0;
	}
	void insert(int x){
		int ss=dfn[x];
		if(s.size()!=0){
			int back,pre;
			if(s.upper_bound(ss)==s.end()){
				set<int>::iterator i=s.end();
				i--,pre=*i,back=*s.begin();
			}else{
				set<int>::iterator i=s.upper_bound(ss);
				back=*i;
				if(i==s.begin()){
					set<int>::iterator j=s.end();
					j--,pre=*j;
				}else i--,pre=*i;
			}
			num-=dis(fg[pre],fg[back]),num+=dis(fg[pre],x)+dis(x,fg[back]);
		}
		s.insert(ss);
	}
	void erase(int x){
		int ss=dfn[x];
		if(s.size()!=0){
			int back,pre;
			if(s.upper_bound(ss)==s.end()){
				set<int>::iterator i=s.end();
				i--,i--,pre=*i,back=*s.begin();
			}else{
				set<int>::iterator i=s.upper_bound(ss);
				back=*i,i--;
				if(i==s.begin()){
					set<int>::iterator j=s.end();
					j--,pre=*j;
				}else i--,pre=*i;
			}
			num+=dis(fg[pre],fg[back]),num-=dis(fg[pre],x)+dis(x,fg[back]);
		}
		s.erase(ss);
	}
	int query(){
		return num/2+1;
	}
	int lcah(){
		if(s.size()==0) return -n;
		int back,pre;
		set<int>::iterator i=s.end();
		i--,pre=*i,back=*s.begin();
		return h[lca(fg[pre],fg[back])];
	}
	int lcas(){
		if(s.size()==0) return -n;
		int back,pre;
		set<int>::iterator i=s.end();
		i--,pre=*i,back=*s.begin();
		return lca(fg[pre],fg[back]);
	}
}prefix,suffix;
void dfs(int pos,int fa){
	h[pos]=h[fa]+1,dfn[pos]=++tot,fg[tot]=pos;
	s.insert({h[pos],pos}),sta[pos]=s.tot;
	for(int i:link[pos]) if(i!=fa) dfs(i,pos),s.insert({h[pos],pos});
}
int dfss(int pos,int fa,int w){
	int res=0;
	for(int i:link[pos]) if(i!=fa) res=max(res,dfss(i,pos,w)+1);
	if(res==w) tag[pos]=true;
	return res;
}
int maxxx;
bool dfsss(int pos,int fa){
	bool num=false;
	for(int i:link[pos]) if(i!=fa){
		if(tag[i]) num=true;
		else num|=dfsss(i,pos);
	}
	tag[pos]|=num;
	return num;
}
void dfssss(int pos,int fa){
	for(int i:link[pos]) if(i!=fa&&!tag[i]) dfssss(i,pos);
	maxxx=max(maxxx,h[pos]);
}
bool check(int x){
	for(int i=1;i<=n;i++) tag[i]=false;
	dfss(1,0,x),maxxx=0;
	prefix.clear(),suffix.clear();
	vector<int>se;
	for(int i=1;i<=n;i++) if(tag[fg[i]]) se.push_back(fg[i]),suffix.insert(fg[i]);
	if(tag[1]) return true;
	dfsss(1,0),dfssss(1,0);
	if(se.size()==0) return true;
	int lcaa=suffix.lcas();
	for(int i=-1;i+1<se.size();i++){
		if(i==-1){
			int num=suffix.query()+max(max(suffix.lcah()-x,0ll)+maxxx-x,0ll);
			if(num<=k) return true;
		}else{
			suffix.erase(se[i]),prefix.insert(se[i]);
			int pl=prefix.lcas(),sl=suffix.lcas();
			int num=suffix.query()+prefix.query()+max(maxxx+max(min(suffix.lcah(),prefix.lcah()),max(max(h[pl]-h[lcaa]-x,h[sl]-h[lcaa]-x),0ll))-x,0ll);
			if(num<=k) return true;
		}
	}
	return false;
}
void does(){
	n=read(),k=read(),s.clear(),tot=0;
	for(int i=1;i<=n;i++) link[i].clear();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		link[u].push_back(v),link[v].push_back(u);
	}
	h[0]=-1,dfs(1,0),s.does();
	if(k>=n){
		cout<<0<<"\n";
		return;
	}
	int l=1,r=n,mid,res=n;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)) r=mid-1,res=mid;
		else l=mid+1;
	}
	cout<<res<<"\n";
}
signed main(void){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	lg[0]=-1;
	for(int i=1;i<=1000000;i++) lg[i]=lg[i>>1]+1;
	c=read(),t=read();
	while(t--) does();
	return 0; 
}
