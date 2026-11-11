#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,op[N],f[N],poss,pos,sum,x,y,l[N],posx,ans,posy;
char chx,chy,ch[N];
map<int,bool> mp;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1; i<=n; ++i){
		scanf("%lld",&op[i]);
		cin >> ch[i];
		l[i]=l[i-1]+op[i];
		sum+=op[i];
	}
	sum>>=1;
	for(int i=1; i<=n; ++i){
		poss+=op[i];
		if(poss>sum)poss=sum;
		if(mp[poss])continue;
		f[++pos]=poss;
		mp[poss]=true;
	}
	poss=0;
	for(int i=n; i>=1; --i){
		poss+=op[i];
		if(poss>sum)poss=sum;
		if(mp[poss])continue;
		f[++pos]=poss;
		mp[poss]=true;
	}
	sort(f+1,f+pos+1);
	for(int i=1; i<=pos; ++i){
		x=f[i];
		y=l[n]-f[i]+1;
		posx=lower_bound(l+1,l+n+1,x)-l;
		posy=lower_bound(l+1,l+n+1,y)-l;
		chx=ch[posx];
		chy=ch[posy];
		if(chx!=chy)ans+=f[i]-f[i-1];
	}
	printf("%lld",ans);
	return 0;
} 
