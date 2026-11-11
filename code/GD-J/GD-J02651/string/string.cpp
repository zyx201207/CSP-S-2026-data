#include<bits/stdc++.h>
using namespace std;
long long a[200005],len,l,ans,r;
char c[200005];
string s;
int main()
{
   	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>c[i];
		len+=a[i];
	}
	long long mid=((n)>>1)-1,r=n-1;
	while(mid>=l)
	{
	  	if(c[l]!=c[r])
	  	{
	  		if(a[l]<a[r])
	  		{
	  			a[r]-=a[l];
	  			ans+=a[l];
	  			l++;
			  }
			  else if(a[l]>a[r]){
			  	a[l]-=a[r];
			  	ans+=a[r];
			  	r--;
			  }
			  else{
			  	ans+=a[l];
			  	l++,r--;
			  }
		  }
		  else{
		  	if(a[l]<a[r])
	  		{
	  			a[r]-=a[l];
	  			l++;
			  }
			  else if(a[l]>a[r]){
			  	a[l]-=a[r];
			  	r--;
			  }
			  else{
			  	l++,r--;
			  }
		  } 
	}
	cout<<ans;
	return 0;
 } 
