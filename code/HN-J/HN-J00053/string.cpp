#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int i,g,a,b=0,e,f,y,h=0;
	string d,c;
	cin>>a;
	for(i=0;i<a;i++)
		cin>>c[i]>>d[i];
	for(i=0;i<a;i++)
	  b=(c[i]-'0')+b;
	if(b%2==0)
	{
	   e=b/2;
	   for(i=0;i<e;i++)
	   {
	   	y=d[i]-'0';
	   	f=d[b-i-1]-'0';
	   	if(y!=f)
	   	  h++;
	   }
	}
	else
	 {
	 	e=(b+1)/2;
	 	for(i=0;i<e-1;i++)
	 	{
	 		y=d[i]-'0';
	 		f=d[b-i-1]-'0';
	 		if(y!=f)
	   	      h++;
		 }
	 }
	 cout<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}	
