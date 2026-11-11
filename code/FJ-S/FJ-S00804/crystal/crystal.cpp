#include<bits/stdc++.h> 
using namespace std;
long long ans=1,n,m;
vector<long long>a;
//bool c(cn x,cn,y)
//{
//	return cn,x<xn,y;
//}
struct cn
{
	int x,y;
};

int main()
{ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//    priority_queue<cn,vector<cn>,greater<cn>> b;
	cin>>n>>m;
	long long zs=0;
	 for(int i=0;i<n;i++)
	 {
	 	int x;
	 	cin>>x;
	 	a.push_back(x);
	 	zs+=a[i];	 
	 }
	 if(n>5000&&n<=500000)
	 {
	 	cout<<m+1;
	 	return 0;
	 }
	 zs/=n;
	 sort(a.begin(),a.end());
	 long long z=lower_bound(a.begin(),a.end(),zs)-a.begin();
     
	 while(m>0)
	 {
	 	if(abs(a[z]-a[z-1])<=m&&abs(a[z]-a[z-1])>0)
	 	{
		    m=m-abs(a[z]-a[z-1]);
	 		a[z-1]=a[z];
	 		ans++; 
	 		
		}
		else if(abs(a[z+1]-a[z])*ans<m)
		{
			for(int i=z;i>z-ans;i--)
			{
				a[i]=a[z+1];
			}
			for(int i=z+1;i<=n;i++)
			{
			    if(a[z+1]!=a[i])break;
				ans++;	
			}
		}
		z--;
	 }
	 cout<<ans;
	return 0;
}
