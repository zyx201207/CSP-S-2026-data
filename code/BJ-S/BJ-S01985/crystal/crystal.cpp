#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;

ll n,m,a[N],p[N],mx,mn,ans,nb;
bool A=true,B=true;

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
		cin>>a[i];
		mx=max(mx,a[i]);
		mn=min(mn,a[i]);
		//A
		if(a[i]!=i) A=false;
		//B
		if(i==1) continue;
		if(i==2) nb=a[i]-a[i-1];
		if(a[i]-a[i-1]!=nb) B=false;
	}
	//A
	if(A)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(i%2==1) cnt++;
			if(ans+1==n) {cout<<ans+1;return 0;}
			if(m-cnt>=0) {ans++;m-=cnt;}
			else {cout<<ans+1;return 0;}
		}
	}
	//B
	if(B)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(i%2==1) cnt+=nb;
			if(ans+1==n) {cout<<ans+1;return 0;}
			if(m-cnt>=0) {ans++;m-=cnt;}
			else {cout<<ans+1;return 0;}
		}
	}
	
	sort(a+1,a+n+1);
	for(ll i=mn;i<=mx;i++)
	{
		int sum=0;
		for(int j=1;j<=n;j++) if(i>a[j])p[j]=i-a[j]; else p[j]=a[j]-i;
		sort(p+1,p+n+1);
		for(ll j=1;j<=n;j++)
		{
			sum+=p[j];
			if(sum<=m) ans=max(ans,j);
			else break;
		}	
	}
	cout<<ans;
    return 0;
}
