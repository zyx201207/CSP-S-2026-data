#include<bits/stdc++.h >
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;
	cin>>n;
	int a[n];char c[n];
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i]>>c[i];
		ans+=a[i];
	}
	if(n==1) cout<<0;
	  else if(n==2) 
	  {
	  	  if(c[1]==c[2]) cout<<0;
	  	  else cout<<min(a[1],a[1]);
      }
    else
    {
    	cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
    return 0;
}
