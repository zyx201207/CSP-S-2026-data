//ГТКЦУњ КывужабЇ GZ-J00452 
#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[200020],a1[200020][32],ans=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	/*	int quan=0;
		 while(a[i])
		 {
		 	a1[i][quan]=a[i]%2+1;
		 	quan++;
		 	a[i]=a[i]/2;
		 }
	}*/
/*	for(int i=0;i<n;i++)
	{
	  for(int j=31;j>=0;j--)
	  {if(a1[i][j]>=1)
	  cout<<a1[i][j]-1;
	  
	}
	cout<<endl;
	}*/
	if(m==1)
	{
		sort(a,a+n);
		cout<<a[n-1];
	}
	else 
	{
		a[0]=a[0]+a[2];
	printf("%d",a[0]);
		
}

	return 0;
 } 
