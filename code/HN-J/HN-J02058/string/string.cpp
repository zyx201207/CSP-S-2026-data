#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200010],s[200010];
char c[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0,l=0,r=0,pl=0,pr=0,ans=0;
	cin>>n;
	string S=""; 
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i],s[i]=s[i-1]+a[i];
	}
	if(sum&1)l=sum/2,r=sum/2+2;
	else l=sum/2,r=sum/2+1;
	pl=lower_bound(s+1,s+n+1,l)-s;
	pr=lower_bound(s+1,s+n+1,r)-s;
	while(pl&&pr<=n){
		int mn=min(l-s[pl-1],s[pr]-r+1);
		if(c[pl]!=c[pr])ans+=mn;
		if(l-s[pl-1]<s[pr]-r+1)pl--;
		else if(l-s[pl-1]>s[pr]-r+1)pr++;
		else pl--,pr++;
		l-=mn,r+=mn;
	}
	cout<<ans<<endl;
	return 0;
}
