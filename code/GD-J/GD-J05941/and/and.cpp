#include <bits/stdc++.h> 
using namespace std;
int n,m,la;

int a[20],a1[20];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int max=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];	
	}
	for(int i=0;i<n;i++)
	{
		a1[i]=a[i]and a[i+1];
		la++;	
	}
	for(int i=1;i<=la;i++)
	{
		if(a1[i]>a1[i-1])
		{
			max=a1[i];
		}
	}
	cout<<max;
	return 0;
}
