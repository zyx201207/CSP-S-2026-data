#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
unsigned long long n,len=0,le=1,re,lp=1,rp,output=0;
struct node
{
	unsigned long long sum;
	char c;
}data[N];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	//cout<<n<<"\n";
	for(int i=1;i<=n;i++)
	{
		//cout<<"当前n:"<<n<<"\n";
		cin>>data[i].sum>>data[i].c;
		len+=data[i].sum;
	}
	//cout<<n<<"\n";
	//cout<<"len:"<<len<<"\n";
	re=len;
	rp=n;
	//cout<<n<<" "<<rp<<"\n";
	for(int i=1;i<=n;i++)
	{
		//cout<<"当前的lp:"<<lp<<" 当前的rp:"<<rp<<"\n";
		//cout<<"当前的le:"<<le<<" 当前的re:"<<re<<"\n";
		if(data[lp].sum<data[rp].sum)
		{
			if(data[lp].c!=data[rp].c)
			{
				output+=data[lp].sum;
			}
			data[rp].sum-=data[lp].sum;
			le+=data[lp].sum;
			re-=data[lp].sum;
			lp++;/*
			if(le>re)//发现右边超过左边，说明超过临界 
			{
				le-=data[lp].sum;
				re+=data[lp].sum;
			}*/
		}
		else  if(data[lp].sum>data[rp].sum)
		{
			if(data[lp].c!=data[rp].c)
			{
				output+=data[rp].sum;
			}
			data[lp].sum-=data[rp].sum;
			le+=data[rp].sum;
			re-=data[rp].sum;
			rp--;
			/*
			if(le>re)//发现右边超过左边，说明超过临界 
			{
				le-=data[rp].sum;
				re+=data[rp].sum;
				
			}*/
		}
		else
		{
			if(data[lp].c!=data[rp].c)
			{
				output+=data[lp].sum;
			}
			lp++;
			rp--;
			le+=data[lp].sum;
			re-=data[lp].sum;
		}
		if(lp==rp||re==le-1)
		{
			cout<<output;
			return 0;
		}
	}
	return 0;
}
