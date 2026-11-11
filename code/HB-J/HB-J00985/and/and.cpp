#include<bits/stdc++.h>

using namespace std;

int n;
int A = 1,B = 2,C = 3,D = 4,F = 5;

int main(){
	freopen("and.in","r",stdin);
	//freopen("and1_ex.in","r",stdin);
	freopen("and.out","W",stdout);
	
	int n,m,s = 0;
	cin>>n>>m;
	int a[1000000];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int Max = 0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=Max)
		{
			Max = a[i];
			s = Max;
		}
	}
	if(m == 1)
	{
		cout<<Max;
	}
	Max = 0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=Max && a[i] != s)
		{
			Max = a[i];
		}
	}
	if(m != 1)
	{
		cout<<Max;
	}
	return 0;
}

