#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m,ans=0;
	string h;
	int len=h.length()=0;
	char c; 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	 cin>>m>>c;
	 for(int j=1;j<=m;j++)
	 {
	 	h+=c;
	 	long long len=h.length();
	 	while(len--)
	 	{
		 int p=1;
		  if(h[len]==h[p]) 
		  {
		  ans++;
		  h[p]=h[len];
  	     }
  	     p--;
  	 }
	 } 
}
cout<<ans;
return 0;
}
