#include<bits/stdc++.h>//1 n 5e5  0 m 1e18  -1e12 a 1e12
using namespace std;//15:01 15:08 15:36 hack
#define ll long long//至多m次 a有负数！ 
const int N=5e5+5;//ned想补平至第i位要几次 
ll n,m,a[N],b[N],t[N],ned[N],cnt[N],dfn[N],d[N],ans;
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
void lisan(){
	for(int i=1;i<=n;i++) t[i]=a[i];
	int num=unique(t+1,t+1+n)-t-1;
	for(int i=1;i<=n;i++){
		b[i]=lower_bound(t+1,t+1+num,a[i])-t;
		cnt[b[i]]++;
		dfn[b[i]]=a[i];
	}
	return ;
}
void solve(){
	for(int i=1;i<=n;i++) b[i]=a[i];
	lisan();
	ll maxn=-1,aim,L,R;
	for(int i=1;i<=n;i++){
		if(maxn<cnt[i]){
			maxn=cnt[i];
			aim=dfn[i];
		}
	}
	bool ok=0;
	for(int i=1;i<=n;i++){
		if(a[i]==aim&&ok==0){
			L=i;
			ok=1;
			continue;
		}
		if(a[i]==aim&&ok) R=i;
	}
	cout<<R-L+1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	if(!m){
		solve();
		return 0;
	}
	for(int i=1;i<=n;i++) d[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++) ned[i]=d[i]*(i-1)+ned[i-1];
	for(int i=1;i<=n;i++){
		if(ned[i]<=m) ans++;
//		cout<<ned[i]<<" ";
	}
	cout<<ans;
	return 0;
}//我要上迷惑行为大赏（坚定 
//期望得分45pts
//没想出来正解 炸了 

