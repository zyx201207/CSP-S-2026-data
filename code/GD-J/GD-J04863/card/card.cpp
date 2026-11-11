#include<bits/stdc++.h>
using namespace std;

long long a[500009];
bool numd[300009];
long long dis_num[300009];

void solve(long long bpc,long long epc)
{
	stack<long long>st_card;
	st_card.push(a[bpc]);
	numd[a[bpc]] = true;
	for(long long i=bpc+1;i<=epc;i++)
	{
		if(numd[a[i]] == false)
		{
			st_card.push(a[i]);
			numd[a[i]] = true;
		}else{
			while(st_card.top() != a[i])
			{
				numd[st_card.top()] = false;
				st_card.pop();
			}
		}
	}
	while(st_card.empty() == false)
	{
		dis_num[st_card.top()]++;
		st_card.pop();
	}
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long N,M;
	cin>>N>>M;
	for(long long i=1;i<=N;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=N;i++)
	{
		for(long long i=1;i<=M;i++)
		{
			numd[i] = false;
		}
		solve(i,N);
	}
	
	for(long long i=1;i<=M;i++)
	{
		cout<<dis_num[i]<<" ";
	}
}
