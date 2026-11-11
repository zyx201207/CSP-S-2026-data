#include <bits/stdc++.h>
using namespace std;
long long n,a[200001],l,r,ans=0,m;
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1,r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;;i++){
		if(a[l]<=0)	l++;
		if(a[r]<=0)	r--;
		if(r<=l)	break;
		m=min(a[l],a[r]);
		a[l]-=m;
		a[r]-=m;
		if(c[l]!=c[r]){
			ans+=m;
		}
	}
	cout<<ans;
	return 0;
}
