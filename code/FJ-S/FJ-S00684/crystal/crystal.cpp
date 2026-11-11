#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,ans,a[N],s[N];
long long check(long long l,long long r,long long k){
	return k*(r-l+1)-(s[r]-s[l-1]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		long long l=1,r=i-1;
		while(l<r){
			int mid=(l+r)>>1;
			if(check(mid,i-1,a[i])>m) l=mid+1;
			else r=mid;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
/*
Ah,si je pouvais vivre dans l'eau,
le monde serait-il plus beau?
Nous pardonneras-tu,o chere mere.
L'eau dans son courant,fait danser nos vies.
Et le cite,elle nourrit.
Ainsi que toi,mon doux amour.

Non,le grand amour ne suffit pas.
Seul un adieu fleurira.
C'est notre histoire de vie,douce et amere.
Moi,je suis et serai toujours la,
a voir le monde et sa beaute.
Et ca ne changera jamais,jamais...
*/
