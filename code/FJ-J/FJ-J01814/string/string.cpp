#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200005],sum=0;
	char c[200005];
	a[0]=0;
	c[0]='A';
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		if(c[i]==c[i-1]){
			a[i-1]+=a[i];
			i--;
			n--;
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		cout<<min(a[1],a[2]);
		return 0;
	}
	long long l=n/2,r=n/2;
	long long ans=0;
	while(l>0 && n<=n){
		if(c[l]==c[r]) ans+=max(a[r]-a[l],a[l]-a[r]);
		else ans+=min(a[l],a[r]);
		l--;
		r++;
	}
	cout<<ans;
	return 0; 
	
}
