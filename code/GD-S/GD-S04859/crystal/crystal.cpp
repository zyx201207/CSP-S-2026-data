#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,mxs,ans_now=0,mxs_now,idx=0;
int main(){
     freopen("crystal.in","r",stdin);
     freopen("crystal.out","w",stdout);
     ios::sync_with_stdio(false);
     cin.tie(nullptr),cout.tie(nullptr);
     cin>>n>>m;
     vector<long long> a(n);
      for(int i=1;i<=n;i++)
      {
      	cin>>a[i];
      
	  }
	  for(int i=1;i<=n;i++)
	  {
      	if(a[i]==a[i-1])
      	{
      		ans++;
      	     mxs=a[i];
      	
		  }
		  else
		  {
		  	if(ans_now>ans)
		  	{
		  		ans=1;
			     mxs=0;
			     
		  		continue;
			  }
			  if(ans>ans_now){
			  idx=i-ans-1;
			  ans_now=ans;
			  mxs_now=mxs;
			  }
			  ans=1;
			  mxs=0;
		  }
      }
      if(idx==-1)
      {
      
      	for(int i=1;;i++)
      	{
		  if(m<(a[i+1]-a[i])*i)
		  {
		  	cout<<i;
		  	return 0;
		  }
      	 m=m-(a[i+1]-a[i])*i;
      	}
      	
      	
	  }
	  else{
	  for(int i=idx;i>=1;i--)
        {
      	if(m==0||m<mxs_now-a[i])
      	{
      		break;
		  }
      	m=m-(mxs_now-a[i]);
      	ans_now++;
	    }
	    cout<<ans_now;
	  }
	  return 0;
 } 
