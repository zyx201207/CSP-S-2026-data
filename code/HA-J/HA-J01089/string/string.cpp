#include<bits/stdc++.h>
using namespace std;
const int N=1e5*2+5;
int n,a[N],ji,tot,sum;
char c_1[N],c[N];
bool b,p;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{int shu;
	 char ch;
	 cin>>shu>>ch;
	 a[i]=shu;
	 c[i]=ch;
	}
	for(int i=2;i<=n;i++)
	  if(a[i]!=a[i-1]) b=1;
	if(b==0)
	{
	 for(int i=n;i>=1;i--)
	 {
	 	if(c[i]!=c[n+1-i]) ji++;
	 }
	 if(ji>0)
	 {cout<<ji/2*a[1]<<'\n';
	  return 0;
	 }
	 else 
	 {cout<<'0';
	  return 0;
	 }
	}
	for(int i=2;i<=n;i++)
	{
	  if(c[i]!=c[i-1]) p=1;
	}
	if(p==0)
	{
	  cout<<'0';
	  return 0;
	}
	for(int i=1;i<=n;i++)
	{
	  for(int j=1;j<=a[i];j++)
	  {
	  	c_1[++sum]=c[i];
	  	tot++;
	  }
	}
	for(int i=tot;i>=1;i--)
	 {
	 	if(c_1[i]!=c_1[tot+1-i]) 
		ji++;
	 }
	 if(ji>0)
	 cout<<ji/2<<'\n';
	 else cout<<'0';
	return 0;
}
