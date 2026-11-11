#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ps putchar(' ')
#define pt putchar('\n')
#define pll pair<long long,long long>
const ll N=607;
const ll M=5e5+7;
const ll INF=0x3f3f3f3f3f3f;
void in(ll &num){
	ll k=1,f=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') k=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		f=f*10+ch-'0';
		ch=getchar();
	}
	num=k*f;
	return;
}
void ot(ll num){
	if(num<0) putchar('-'),num*=-1;
	if(num>9) ot(num/10);
	putchar(num%10+'0');
	return;
}
void out(ll num){
	ot(num),ps;
	return;
}
ll c,n,m,d,q,minn=INF;
ll len[N][N],win[M];
vector<pll > e[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	in(c),in(n),in(m),in(d),in(q);
	memset(len,INF,sizeof(len));
	for(ll i=1;i<=m;i++) in(win[i]);
	for(ll i=1;i<=n;i++){
		ll k;
		in(k);
		for(ll j=1;j<=k;j++){
			ll v,w;
			in(v),in(w);
			e[v].push_back({i,w});
		}
	}
	for(ll i=1;i<=m;i++){
		for(ll j=0;j<e[i].size();j++){
			for(ll k=j+1;k<e[i].size();k++){
				ll va=e[i][j].first,vb=e[i][k].first;
				ll wa=e[i][j].second,wb=e[i][k].second;
				len[va][vb]=min(len[va][vb],wa+wb);
				len[vb][va]=min(len[vb][va],wa+wb);
			}
		}
	}
	for(ll i=1;i<=n;i++) len[i][i]=0ll;
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=n;j++){
			for(ll k=1;k<=n;k++){
				len[i][j]=min(len[i][j],len[i][k]+len[k][j]);
			}
		}
	}
	for(ll i=1;i<=q;i++){
		ll l,r;
		in(l),in(r);
		minn=INF;
		for(ll j=0;j<e[l].size();j++){
			for(ll k=0;k<e[r].size();k++){
				ll va=e[l][j].first,vb=e[r][k].first;
				ll wa=e[l][j].second,wb=e[r][k].second;
				minn=min(minn,len[va][vb]+wa+wb);
			}
		}
		minn=minn+win[l]+win[r];
		out(minn),pt;
	}
	return 0;
}
/*
cd C:\Users\Administrator\Desktop\GD-S01884\subway
fc /w /n subway.out subway1.ans
*/
