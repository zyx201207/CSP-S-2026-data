//GZ-J00427 兴义市弘毅中学 罗曾琦 
#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,r=0; 
long long a[1100000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		r=max(r,a[i]);
	 }  
	if(m==2){
		for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			ans=max(ans,a[i]&a[j]);
		}
	}
	  cout<<ans;
	}
	if(m==n&&n!=2){
		ans=a[0]&a[1];
		for(int i=2;i<n;i++)
		{
			ans=ans&a[i];
		}
		cout<<ans;
	}
	if(m==1)
	{
		cout<<r;
	}
    return 0;
 } 
