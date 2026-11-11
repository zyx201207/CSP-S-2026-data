#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a,b;
	int sum=0,cnt=0;
	string n,m;
	cin>>a>>n>>b>>m;
	string w=n,q=m;
	if(n[2]=='A'||n[2]=='B'||n[2]=='C')
	{
		n[2]='1';
	}
	if(m[2]=='A'||m[2]=='B'||m[2]=='C')
	{
		m[2]='1';
	}
	if(a==b)
	{
		cout<<1;
	}
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(n[0]==m[0]&&n[1]==m[1])
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(n[0]==m[0]&&n[1]==m[1]&&n[2]=='1'&&m[2]=='1'||n[2]!='1'&&m[2]!='1')
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	int s=(n[0]-48)*10+n[1]-48;
	int g=(m[0]-48)*10+m[1]-48;
	int k=w[2]-65;
	int r=q[2]-65;
	if(n[2]!=m[2])
	{
		cout<<0;
		return 0;
	}
	if(s-g==0||g-s==0)
	{
		sum+=3;
	}
	if(s-g==1||g-s==1)
	{
		sum+=1;
	}
	if(sum==0)
	{
		cout<<0;
		return 0;
	}
	if(k-r==1||r-k==1)
	{
		cnt+=1;
	}
	if(k-r==0||r-k==0)
	{
		cnt+=3;
	}
	if(cnt==0)
	{
		cout<<0;
		return 0;
	}
	if(sum+cnt==2)
	{
	   cout<<0; 
	} 
	else
	{
		cout<<1;
	}
	return 0;
}  
