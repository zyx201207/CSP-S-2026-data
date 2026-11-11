#include<bits/stdc++.h>
using namespace std;
int n,s=0;
long long m;
int a[500001]={0};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int z=a[n]/2;
	int y=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>z)
		{
			y=i-1;
			break;
		}
	}
	for(int i=y;i>=1;i--)
	{
		int q;
		q=z-a[i];
		if(m>=q)
		{
			s+=1;
		}
	}
	cout<<s<<endl;
	
	return 0;
}
