#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10;

ll n,a[N],sum,l,ls,r,rs,ans,b;
char c[N];

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(ll i=1;i<=n;++i)
		cin>>a[i]>>c[i];
	l=1,r=n;
	
	while(l<r){sum=0;
		b=(c[l]!=c[r]);
		if(a[l]-ls>a[r]-rs)
			sum=(a[r]-rs),
			ls+=(a[r]-rs),
			--r,rs=0;
		else if(a[l]-ls<a[r]-rs)
			sum=(a[l]-ls), 
			rs+=(a[l]-ls),
			++l,ls=0;
		else
			sum=(a[l]-ls),
			++l,--r,ls=rs=0;
		ans+=b*sum;
	}
	
	cout<<ans;
	
	return 0;
}           
