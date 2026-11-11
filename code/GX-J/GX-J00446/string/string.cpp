#include<bits/stdc++.h>
using namespace std;
string a,b;
int s=0;
int main()
{
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  int n,c;
  char d;
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>c>>d;
    a[s]=d;
    b[s]=d;
    s=s+c;
  }
  b[s-1]=d;
  int x=0,e=s/2;
  for(int i=1;i<=e;i++)
  {
	if(i>=2)
	{
	  a[i-1]=a[i-2];
	  b[s-i]=b[s-i+1];
	}
    if(a[i-1]!=b[s-i])
      x++;
  }
  cout<<x;
  return 0;
}
