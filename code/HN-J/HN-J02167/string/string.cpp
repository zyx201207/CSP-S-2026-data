#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,i;
	cin>>n;
	long long a;  string s,c;  
	for(i=0;i<n;i++)
	{
		cin>>a>>c;
		while(a)
		{
			s=s+c;
			a--;
		}	
	}
	int l;
	int t=0;
	l=s.size();
	for(i=0;i<l/2;i++)
	  if(s[i]!=s[l-(i+1)])
	  {
	  	  s[l+1-i]=s[i];
	  	  t++;
	  }
	cout<<t;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
