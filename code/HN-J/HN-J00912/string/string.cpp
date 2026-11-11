#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N],len,ma,ans,l[N],r[N],i=1,si,sma;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	ma=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l[i]=r[i-1]+1,r[i]=l[i]+a[i]-1,len+=a[i];
	}
	for(int i=1;i<=n;i++){
		if(l[i]>len/2)
			l[i]=len-l[i]+1;
		if(r[i]>len/2)
			r[i]=len-r[i]+1;
	}
	while(i<ma){
		if(c[ma]!=c[i]){
			ans+=min(r[i],l[ma])-max(l[i],r[ma])+1;
		}
		si=i,sma=ma;
		if(r[i]>=l[ma])
			sma--;
		if(r[i]<=l[ma])
			si++;
		i=si,ma=sma;
	}
	cout<<ans;
	return 0;
}
