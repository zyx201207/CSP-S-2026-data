#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll n,x,nl[N],nr[N],sum,ans;
char ch[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;	
	for(int i=1;i<=n;i++){
		cin>>x>>ch[i];
		sum+=x,nl[i]=nr[i-1]+1,nr[i]=nl[i]+x-1;
	}
	ll l,r;
	if(sum&1)l=r=sum/2+1;
	else l=sum/2,r=sum/2+1;
	while(l>=1&&r<=sum){
		ll lpos=lower_bound(nr+1,nr+n+1,l)-nr;
		ll rpos=lower_bound(nr+1,nr+n+1,r)-nr;
		ll ldis=l-nl[lpos];
		ll rdis=nr[rpos]-r;
		ll mn=min(ldis,rdis);
		if(ch[lpos]!=ch[rpos])ans+=mn+1;
		l-=mn,r+=mn;
		l--,r++;
	}
	cout<<ans;
	return 0;
}
