#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)
		scanf("%lld %c",a+i,c+i);
	ll i=1,j=n,inum=a[1],jnum=a[n];
	while(i<j){
		if(c[i]!=c[j])ans+=min(inum,jnum);
		if(inum==jnum)i++,j--,inum=a[i],jnum=a[j];
		else if(inum>jnum)inum-=jnum,j--,jnum=a[j];
		else jnum-=inum,i++,inum=a[i];
	}cout<<ans;
	return 0;
}
