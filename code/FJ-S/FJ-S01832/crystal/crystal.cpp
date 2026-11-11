#include<bits/stdc++.h>
using namespace std;
long long n,a[501001],s[501010],m,ans,pd,z;
map<long long,int>mp;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	 {
	 	cin>>a[i];
	 }
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	 {
	 	pd=1;
	 	s[i]=a[i+1]-a[i];
	 	m-=s[i]*i;
	 	if(m<0)
		 {
		 ans=i;
		 if(i==1) pd=0;
		 break;}
	 }
	if(pd&&ans==0) cout<<n;
	if(!pd)
	 {
	 	for(int i=1;i<=n;i++)
	 	 {
	 	 	mp[a[i]]++;
	 	 	if(a[i]!=a[i+1])
	 	 	 {
	 	 	 	z=mp[a[i]];
	 	 	 	ans=max(ans,z);
			   }
		  }
	 }
	if(pd==1&&ans!=0) cout<<ans;
	return 0;
}