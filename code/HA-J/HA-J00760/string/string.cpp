#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){ int x=0,f=1;char ch=getchar();while(!isdigit(ch)){ if(ch=='-'){ f=-1; }ch=getchar(); }while(isdigit(ch)){ x=(x<<3)+(x<<1)+(ch^48);ch=getchar(); }return x*f; }
inline void write(int x){ if(x<0){ putchar('-');x=-x; }int cnt=0;char c[23];do{ c[++cnt]=x%10|48;x/=10; }while(x);while(cnt){ putchar(c[cnt--]); }putchar(' '); }
const int mod=998244353,N=1000005;
int n,a[N<<1];char c[N];
int L;
struct node{
	char c;
	int len;
};
queue<node> q1,q2;
stack<node> tmp;
signed main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];L+=a[i];
	}
	int now=0,lst=0,i=1;
	for(i=1;i<=n;i++){
		now+=a[i];
		if(now>L/2){
			if(L&1){
				if(lst<L/2)q1.push((node){c[i],L/2-lst});
				if(now>L/2+1)q2.push((node){c[i],now-L/2-1});
			}else{
				if(lst<L/2)q1.push((node){c[i],L/2-lst});
				if(now>L/2)q2.push((node){c[i],now-L/2});
			}
			i++;break;
		}else{
			q1.push((node){c[i],a[i]});
		}
		lst=now;
	}
	for(;i<=n;i++){
		q2.push((node){c[i],a[i]});
	}
	while(q2.size()){tmp.push(q2.front());q2.pop();}
	while(tmp.size()){q2.push(tmp.top());tmp.pop();}
	int lnow=q1.front().len,rnow=0,ans=0;char lc=q1.front().c,rc;q1.pop();
	while(q1.size()||q2.size()){
		//cerr<<q1.size()<<" "<<q3.size()<<"\n";
		if(lnow<rnow){
			node ls=q1.front();q1.pop();
			ans+=min(rnow-lnow,ls.len)*(ls.c!=rc);
			lc=ls.c;lnow+=ls.len;
		}else{
			node ls=q2.front();q2.pop();
			ans+=min(lnow-rnow,ls.len)*(lc!=ls.c);
			rc=ls.c;rnow+=ls.len;
		}
	}
	cout<<ans;
	return 0;
}
