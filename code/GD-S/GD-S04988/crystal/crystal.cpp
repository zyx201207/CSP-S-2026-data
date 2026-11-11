#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n , m ,l , r ,ans = -1;
	cin >> n >> m;
	
	
	
	
	if(n<=5000) 
	{
	int a[10005]={};
	for(int i=1;i<=n;i++)
	{
		cin >> a[i]; 
	}
	sort(a+1,a+n+1);
	l=1;
	r=1;
	
	while(r <= n)
	{
		int sum = 0,msum=0;
		for(int j=l;j<=r;j++)
		{
			msum += a[r]-a[j];
		}
		//cout << "l=" <<l <<" r=" <<r<<endl;
		//cout << "msum=" <<msum << endl;
		if(msum <= m) 
		{	
		ans = max(ans,r-l+1);
		
		//cout << "r-l+1="<< r-l+1 << endl;
		r++;
		}
		else 
		{
			l++;
		}
	}
	cout << ans;
	}
	
	
	
	
	else
	/*{
	int s[220]={};
	
	int xb =1;
	short a[1000005]={};
	for(int i=1;i<=n;i++)
	{
		int f;
		scanf("%d",&f);
		s[f+100]++;
		//cout << endl << "i=" << i << endl;
	}
	for(int i=0;i<=215;i++)
	{
		for(int j=1;j<=s[i];j++) 
		{
			a[xb]=i-100;
			xb++;
		}
	}
	//for(int i=1;i<=n;i++) cout << a[i] << " ";
	l=1;
	r=1;
	
	while(r <= n)
	{
		int sum = 0,msum=0;
		for(int j=l;j<=r;j++)
		{
			msum += a[r]-a[j];
		}
		//cout << "l=" <<l <<" r=" <<r<<endl;
		//cout << "msum=" <<msum << endl;
		if(msum <= m) 
		{	
		ans = max(ans,r-l+1);
		
		//cout << "r-l+1="<< r-l+1 << endl;
		r++;
		}
		else 
		{
			l++;
		}
	}
	cout << ans;
	}*/
	{
		int f,sum1=1,sum2=0;
		short a[500005]={};
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&f);
			a[i]=f; 
		}
		 while(sum2<=m)
		 {
		 	sum2 = sum1 + sum2;
		 	sum1++;
		 	//cout << "sum1 " <<sum1<< " sum2 "<<sum2 << endl;
		 }
		 cout << sum1-1;
	}
	
	
	return 0;
}
