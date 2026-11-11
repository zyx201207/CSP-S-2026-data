#include<bits/stdc++.h>
using namespace std;
#define M 500005
long long n,m,a[M],b[M],s[M],l,sum,ans,mum;
int main()
{
 freopen("crystal.in","r",stdin);
 freopen("crystal.out","w",stdout);
 cin>>n>>m;
 for(int i=1;i<=n;i++)
 {
	 cin>>a[i];
 }
 sort(a+1,a+n+1);
 for(int i=1;i<n;i++)
 {
	 mum+=a[n]-a[i];
	 s[i]=a[i+1]-a[1];
 }

 if(m>=mum){
	 cout<<n;
	 return 0;
	 }
 ans=1;
 for(int i=1;i<n;i++)
 {
	 l=1;
	 sum=0;
	 while(sum<m&&l<n&&i+l-1<n)
	 {
		 sum+=l*(s[i+l-1]-s[i+l-2]);


		 l++;
		 }

	 ans=max(ans,l);
 }
 cout<<ans;
  return 0;

  }
