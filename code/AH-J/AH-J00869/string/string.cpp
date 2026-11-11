#include<bits/stdc++.h>
using namespace std;
char s[60000050];
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n,x,t=0,m=0;
char y;
cin>>n;
for(int i=0;i<n;i++)
{
	cin>>x>>y;
	while(x>0)
	{
		s[t++]=y;
		x--;
	}
}
for(int i=0,j=t-1;i<=j;i++,j--)
{
	if(s[i]!=s[j])
	m++;
}
cout<<m;
fclose(stdin);
fclose(stdout);
return 0;
}

