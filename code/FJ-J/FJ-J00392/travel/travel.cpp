#include<iostream>
using namespace std;
string a,b,c,d;
bool f[5];
inline int read(){char cc=getchar();int z=0,fh=1;while((cc<'0' || cc>'9') && cc!='-'){cc=getchar();}if(cc=='-'){fh=-1;cc=getchar();}while(cc>='0' && cc<='9'){z=z*10+cc-'0';cc=getchar();}return z*fh;}
inline void write(int x){if(x==0){putchar('0');return ;}if(x<0){putchar('-');x=-x;}int z[20],tt=0;while(x){z[++tt]=x%10;x/=10;}for(int i=tt;i;i--){putchar(z[i]+'0');}}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		f[1]=true;
	}
	if(f[1] && b[0]==d[0] && b[1]==d[1])
	{
		f[2]=true;
	}
	if(f[2] && ((b[2]>='A' && b[2]<='C' && d[2]>='A' && d[2]<='C') || (b[2]>='D' && b[2]<='F' && d[2]>='D' && d[2]<='F')))
	{
		f[3]=true;
	}
	if(f[3] && max(b[2]-d[2],d[2]-b[2])==1)
	{
		f[4]=true;
	}
	for(int i=1;i<=4;i++)
	{
		putchar('0'+f[i]);
	}
	
	return 0;
}
