#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[201000];
string s[201000];
inline void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>s[i];
	ll ans=0,l=1,l2=a[l],r=n,r2=a[r];
	while(1){
		if(l2>r2){
			if(s[l]!=s[r])ans+=r2;
			l2-=r2,r2=a[--r];
		}
		else if(l2==r2){
			if(s[l]!=s[r])ans+=r2;
			l2=a[++l],r2=a[--r];
		}
		else{
			if(s[l]!=s[r])ans+=l2;
			r2-=l2,l2=a[++l];
		}
		if(l==n+1&&r==0)break;
	}
	cout<<ans/2<<"\n";
	return;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)
		solve();
	return 0;
}
