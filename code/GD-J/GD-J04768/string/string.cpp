#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	int len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	int l=0,r=n+1,cnt=0;
	int pl,pr;
	char cl,cr;
	while(cnt<len/2){
		l++; cnt+=a[l];
	}
	cl=c[l],pl=len/2-(cnt-a[l]);
	cnt=0;
	while(cnt<len/2){
		r--; cnt+=a[r];
	}
	cr=c[r],pr=len/2-(cnt-a[r]);
	int ans=0;
	while(l>=1&&r<=n){
		int p=min(pl,pr);
		if(cl!=cr) ans+=p;
		pl-=p,pr-=p;
		if(!pl) l--,pl=a[l],cl=c[l];
		if(!pr) r++,pr=a[r],cr=c[r];
	}
	cout<<ans<<'\n';
}
