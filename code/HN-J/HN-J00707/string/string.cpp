#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
long long t1[maxn],t2[maxn],n,ans;
long long sum;
char m[maxn];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int c=0;
	for(int i=1;i<=n;i++)
	{
		cin>>t1[i]>>m[i];
		t2[i]=t1[i];
		sum+=t1[i];
	}
	long long mid=sum/2;
	long long d=1,i=1,e=n;
	while(i<=mid)
	{
		//cout<<i<<" "<<d<<" "<<e<<" "
		//cout<<ans;
	if(t1[d]==t2[e])
	{
		if(m[d]!=m[e])
      {
      	ans+=t2[e];
      	//cout<<ans;
      	i+=t2[e];
      	e--;
      	d++;
      	continue;
}
else
{
	i+=t1[d];
	  d++;
	  e--;
	  continue;
}
	}
	
     if(t1[d]>t2[e])
     {
     	if(m[d]!=m[e])
      {
      	
      	ans+=t2[e];
      		//cout<<t2[e]<<(i+t2[e]-1)%mid<<ans;
      	t1[d]-=t2[e];
      	i+=t2[e];
      	e--;
      	continue;
	  }
	  else
	  {
	  i+=t2[e];
	  t1[d]-=t2[e];
	  e--;
	  continue;
	  }
	  
	 }
      
	  else
	  {
	  		if(m[d]!=m[e])
	  	{
	  			
	  		ans+=t1[d];
	  		//cout<<(i+t1[d]-1)%mid<<" "<<t1[d];
	  			//cout<<ans;
	  	t2[e]-=t1[d];
	  	i+=t1[d];
	  	d++;
	  	continue;
		  } else
	  {
	  i+=t1[d];
	  t2[e]-=t1[d];
	  d++;
	  continue;
	  }
	  	
	  }
	}
	cout<<ans;
	return 0;}

