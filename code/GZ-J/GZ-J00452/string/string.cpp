//³ÂºÆÃú GZ-J00452 ºëÒãÖĞÑ§ 
#include<bits/stdc++.h>
using namespace std;
long long int n,a[100000000],h=0,r=0,bs,ans=0;
char c[100000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
//cin>>n;
	getchar();
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
//	cin>>a[i];
		getchar();
	scanf("%c",&c[i]);	//cin>>c[i];
	}
/*	for(int i=0;i<n;i++)
	{
		//cout<<a[i]<<" "<<c[i]<<endl;
		printf("%lld  ",a[i]);
	     printf("%c \n",c[i]);
	}*/
/*	if(n%2!=0)
	{
		bs=(n/2);
	}
	else{
		bs=n/2-1;
	}*/
/*for(int i=0;i<n;i++)
	{
		r+=a[i];
	}*/
	r=n-1;
	while(h<=r)
	{
		if(a[h]>a[r])
		{
			if(c[h]!=c[r])
			{
			ans=ans+a[r];
			}
        	a[h]=a[h]-a[r];
        	r--;
		}
		else if(a[h]<a[r])
		{
				if(c[h]!=c[r])
			{
			ans=ans+a[h];
			}
        	a[r]=a[r]-a[h];
        	h++;
		}
		else{
		if(c[h]!=c[r])
			{
				ans=ans+a[h];
				
			}
			r--;
		    h++;
		}
	}
	printf("%lld\n",ans);
	return 0;
 } 
