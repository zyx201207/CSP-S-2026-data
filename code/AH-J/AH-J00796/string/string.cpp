#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e5+5;
LL n,a[N],ans,maxn;
string c[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		maxn=max(maxn,a[i]);
	}
	if(n*maxn<1e8){
		for(LL i=1;i<=n;i++){
			for(LL j=1;j<=a[i];j++) s+=c[i];
		} 
		LL x=0;
		if(s.size()%2==0) x=s.size()/2+1;
		else x=s.size()/2;
		LL p=-1;
		for(LL i=s.size()-1;i>=x;i--){
			p++;
			if(s[i]!=s[p]) ans++;
		}
		cout<<ans;
	}
	else{
		LL p=0;
		for(LL i=n;i>=n/2+1;i--){
			p++;
			if(c[i]!=c[p]) ans+=a[i];
		}
		cout<<ans;
	}
	return 0;
}
