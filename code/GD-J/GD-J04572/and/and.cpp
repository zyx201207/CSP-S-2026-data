#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,ls,output=0,ls1,ls2,period[N][5];
char lss[N];
struct node
{
	long long num;
	string s;
}data[N];

inline int cmp(node a,node b)
{
	if(a.s>b.s)
	{
		return 1;
	}
	return 0;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>data[i].num;
		ls=data[i].num;
		data[i].s.push_back('0'+data[i].num%2);
		data[i].num/=2;
		while(data[i].num)
		{
			data[i].s=char('0'+data[i].num%2)+data[i].s;
			data[i].num/=2;
		}
		while(data[i].s.size()<31)
		{
			data[i].s='0'+data[i].s;
		}
		data[i].num=ls;
	}
	sort(data+1,data+n+1,cmp);/*
	for(int i=1;i<=n;i++)
	{
		cout<<data[i].num<<" "<<data[i].s<<"\n";
	}*/
	for(int i=0;i<=30;i++)
	{
		ls1=0;
		ls2=0;
		for(int j=1;j<=n;j++)
		{
			lss[j]=data[j].s[i];
			//cout<<lss[j]<<" "; 
			//cout<<"第"<<i<<"的第"<<j<<"位:"<<((!ls1)&&(lss[j]=='1'))<<"\n";
			ls1=((!ls1)&&(lss[j]=='1'))?j:ls1;
			ls2=((ls1)&&(!ls2)&&lss[j]=='0')?j:ls2;
		}/*
		cout<<"第"<<i<<"个串:";
		for(int j=1;j<=n;j++)
		{
			cout<<lss[j];
		}
		cout<<"\n";
		/*
		if(!lss[ls1])
		{
			ls1=0;
			ls2=0;
		}
		else
		{
			if(lss[ls2])
			{
				ls2++;
			}
		}*/
		//cout<<"对于第"<<i<<"位，其1的区间为"<<ls1<<"-"<<ls2-1<<"\n";
		if(ls2-ls1>=m)
		{
			output=data[ls1].num;
			for(int i=ls1+1;i<=ls1+m-1;i++)
			{
				output&=data[i].num;
			}
			cout<<output;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
