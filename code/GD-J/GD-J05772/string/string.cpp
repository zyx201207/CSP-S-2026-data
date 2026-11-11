#include<bits/stdc++.h>
using namespace std;
long long n,i,a[1000001],ans,p,l,r,t;
string s[300001];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++) {
		cin>>a[i]>>s[i];
	}
	l=1,r=n;
	while(l<r) {
		p=min(a[l],a[r]);
		if(s[l]!=s[r]) ans+=p;
//		cout<<p<<" "<<ans<<endl;
		if(a[l]<a[r])  {
			a[r]-=a[l];
			l++;
		}
		else if(a[l]==a[r]) {
			l++;
			r--;
		}
		else {
			a[l]-=a[r];
			r--;
		}
//		cout<<l<<" "<<r<<endl;
//		t++;
//		if(t==3) break; 
	}
	cout<<ans;
}
