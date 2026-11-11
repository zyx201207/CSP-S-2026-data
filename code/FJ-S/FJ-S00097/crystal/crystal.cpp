#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],aa[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m>100000010){
		m*=2;
		m/=a[2]-a[1];
		long long s=sqrt(m);
		if(s*(s+1)>m)cout<<min(n,s);
		else cout<<min(n,s+1);
	}
	else{
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1]) aa[i]=aa[i-1]+1;
			else{
				long long k=m,j;
				for(j=i-1;j>=1&&k>=a[i]-a[j];j--) k-=a[i]-a[j];
				aa[i]=i-j;
			}
			ans=max(ans,aa[i]);
		}
		cout<<ans;
	}
	return 0;
}
