#include<iostream>
#include<cmath>
using namespace std;
struct zf
{
  long long v;
  char c;
}a[200005],b[200005],c[200005];
int main()
{
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  long long n,s[200005],xb,ans1=0;
  cin>>n;
  s[0]=0;
  for(long long i=1;i<=n;i++)
  {
  	cin>>a[i].v>>a[i].c;
  	s[i]=s[i-1]+a[i].v;
  }
  long long sum=0;
  for(long long i=1;i<=n;i++)
  {
  	sum+=a[i].v;
  	if((sum>=s[n]/2&&s[n]%2==0)||(sum>=s[n]/2+1&&s[n]%2==1))
  	{
  	  xb=i;
  	  break;
	}
  }
  for(long long i=1;i<=xb;i++)
  {
  	if(i==xb)
  	{
  	  if(s[n]%2==0)
  	    b[i].v=s[n]/2-s[xb-1];
  	  else
  	    b[i].v=s[n]/2-s[xb-1];
	  b[i].c=a[xb].c;
	  break;
    }
    b[i].v=a[i].v;
    b[i].c=a[i].c;
  }
  for(long long i=n;i>=xb;i--)
  { 
    if(i==xb)
    {
      if(b[i].v==a[i].v)
      	break;
      if(s[n]%2==0)
      	c[i].v=a[xb].v-b[xb].v;
      else
      	c[i].v=a[xb].v-b[xb].v-1;
      c[i].c=a[i].c;
      break;
	}
	c[n-i+1].v=a[i].v;
	c[n-i+1].c=a[i].c;
  } 
  for(int i=1;i<=xb;i++)
    cout<<b[i].v<<' '<<b[i].c<<endl;
    cout<<endl;
  for(int i=1;i<=n-xb+1;i++)
    cout<<c[i].v<<' '<<c[i].c<<endl;
    cout<<s[n]<<' '<<xb<<endl;
  long long x=1,y=1;
  while(x<=xb+1&&y<=n-xb+1)
  {
  	if(b[x].c!=c[y].c)
  	{
  	  if(b[x].v>c[y].v) 
  	  {
  	  	ans1+=c[y].v;
  	  	b[x].v-=c[y].v;
  	  	y++;
	  }
	  else if(b[x].v<c[y].v)
	  {
	  	ans1+=b[x].v;
	  	c[y].v-=b[x].v;
	  	x++;
	  }
	  else
	  {
	  	ans1+=b[x].v;
		x++;
		y++;
	  }
	}
	else
	{
      if(b[x].v>c[y].v) 
  	  {
  	  	b[x].v-=c[y].v;
  	  	y++;
	  }
	  else if(b[x].v<c[y].v)
	  {
	  	c[y].v-=b[x].v;
	  	x++;
	  }
	  else
	  {
		x++;
		y++;
	  }
    }
  }
  cout<<ans1;
  return 0;
 } 
//ÕâÆÚÒõÁË 
