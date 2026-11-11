#include<bits/stdc++.h>
using namespace std;
int a[20050],ant=0,n;
void q(int s,int m)
{
	if(m==0)
	return ;
	for(int i=0;i<n;i++)
	{
		s=s&a[i];
		ant=max(ant,s);
		q(s,m-1);
	}
}
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int m;
cin>>n>>m;
for(int i=0;i<n;i++)
cin>>a[i];
for(int i=0;i<n;i++)
q(a[i],m-1);
cout<<ant;
fclose(stdin);
fclose(stdout);
return 0;
}

