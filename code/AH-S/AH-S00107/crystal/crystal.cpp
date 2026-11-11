#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010],ans=0,t=1,c=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
	}
	sort(a+1,a+1+n);
	if(ans-a[n]*n<=m){
		cout<<a[n];
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i]){
			t=0;
		}
	}
	if(t==1){
		long long d=a[2]-a[1];
		if(n%2==0){
		long long l=n/2,r=n/2+2;
		while(l>=1&&r<=n){
			c+=d*(n/2+1-l);
			if(c>m) break;
			l--;
			c+=d*(r-n*2-1);
			if(c>m) break;
			r++;
		}
		cout<<r-l+1;
	}
	else{
		long long l=n/2,r=n/2+2;
		while(l>=1&&r<=n){
			c+=d*(n/2-1);
			if(c>m) break;
			l--;
			c+=d*(r-n*2-1);
			if(c>m) break;
			r++;
		}
			cout<<r-l+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}

