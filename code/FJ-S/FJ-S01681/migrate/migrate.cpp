#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
bool vis=false;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d;
		long long a[N];
		long long xans=0,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]-a[i-1]<=d) xans++;
			if(a[i]<0) vis=true;
		}
		if(vis==true) ans-=1;
		long long l=xans%4;
		cout<<l<<endl;
		if(l==0) ans=xans/4;
		else ans+=(xans-l)/4+l;
		cout<<ans<<endl;
	}
	return 0;
 } 
