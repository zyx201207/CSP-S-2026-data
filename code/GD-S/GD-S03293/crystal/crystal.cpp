#include<bits/stdc++.h>
using namespace std;
const int nx1=1e5+5; 
int n,x=1;
long long m,a[nx1];
bool px(int a,int b)
{
	return a<b;
}
int main(){
	preopen("poker.in","r",stdin);
	preopen("poker.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,px);
	for(int i=n-1;i>0;i--)
	{
		if(i<x)
			break;
		for(int j=i,k=m,x1=1;j>0&&k>0;j--)
		{
			if(k<a[j]-a[j-1])
				break;
			if(a[j]-a[j-1]<=k)
			{
				k-=a[j]-a[j-1];
				x1++;
			}
			if(x1>x)
				x=x1;
		}
	}
	cout<<x;
	return 0;
}

