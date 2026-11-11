#include <bits/stdc++.h>
using namespace std;

const int N=1e5*5+10;
int n;
long long m;
long long arr[N];
long long pre_[N];

bool flag1=true;
bool flag2=true;

int main(){
	
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin>>n>>m;
	long long cha=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>arr[i];
		if(arr[i]!=i) flag1=false;
		
		if(i==1) continue;
		else if(i==2) cha=arr[i]-arr[i-1];
		else if(arr[i]-arr[i-1]!=cha) flag2=false;
	}
	
	if(flag1)
	{
		long long id=1;
		while(m-id>0||id==n)
		{
			m-=id;
			id++;
		}
		cout<<id;
		return 0;
	}
	
	if(flag2)
	{
		cha=abs(cha);
		long long id=cha;
		while(m-id>0||id==n)
		{
			m-=id;
			id+=cha;
		}
		cout<<id;
		return 0;
	}
	
	sort(arr+1,arr+1+n);
	for(int i=1;i<=n;i++) 
	{
		if(i!=1) pre_[i-1]=arr[i]-arr[i-1];
	}
	
	int id=1;
	while(m-pre_[id]>0||id==n)
	{
		m-=pre_[id];
		id++;
	}
	cout<<id;
	
return 0;}
