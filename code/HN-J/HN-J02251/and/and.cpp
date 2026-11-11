#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000005];
string s[100005];
long long tt[1000005];
long long zd=-1;
void zh(long long x,int y)
{
	while(x!=0)
	{
		if(x%2!=0)
		{
			s[y]='1'+s[y];
			tt[y]++;
		}
		else
		{
		s[y]='0'+s[y];
		tt[y]++;
		}
		
		x=x/2;
	//	cout<<s[y]<<"  ";
	}
	
	return;
}
long long zh2(string x)
{
	long long ans=0;
	for(int i=0;i<x.length();i++)
	{
		if(x[i]=='1'&&i!=x.length()-1)
		{
			long long cnt=1;
			for(int j=1;j<x.length()-i;j++)
			{
				
				 cnt=cnt*2;
			}
			ans+=cnt;
		}
		else
		if(x[i]=='1')
		{
			ans++;
		}
	}
	return ans;
}
void bj(int x,string y,long long l)
{
	if(l==0)
	{
		if(zh2(y)>zd)
		{
			zd=zh2(y);
		}
		
	}
	
	for(int j=1;j<=n;j++)
	{
		if(j!=x&&s[j]!="xx")
		{
			string s3=s[j];
		//	cout<<j<<"  "<<x<<"  "<<s3<<"  "<<y<<"xx";
				while(tt[x]!=tt[j])
				{
			//		cout<<"ww";
					if(tt[x]>tt[j])
					{
						tt[j]++;
						s3='0'+s3;
					}
					else
					if(tt[x]<tt[j])
					{
						tt[x]++;
						y='0'+y;
					}
				}
		//		cout<<"s3=="<<s3<<endl;
		//		cout<<"y=="<<y<<endl;
				string s2;
			for(int i=0;i<tt[x];i++)
			{
				
				if(y[i]==s3[i]&&y[i]=='1')
				{
					s2=s2+'1';
		//			cout<<"yy";
				}
				else
				{
					s2=s2+'0';
				}
			}
		//	cout<<"s2=="<<s2<<endl;
			string h=s[j];
			s[j]="xx";
			bj(x,s2,l-1);
			s[j]=h;	
			
		}
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		zh(a[i],i);
	}
	for(int i=1;i<=n;i++)
	{
//		cout<<"s[i]=="<<s[i]<<endl;
		bj(i,s[i],m);
	}
	
	cout<<zd;
	return 0;
}
// Trick||Treat! 
//00011
//00011
//01100
//01111

