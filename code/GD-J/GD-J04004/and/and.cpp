#include<bits/stdc++.h> 
using namespace std;
com(int a,int b)
{
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[n];
	long long maxn=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,com);
	 
	for(int i=0;i<n;i++)
	{
		int js=a[i];
		for(int j=i+1;j<i+m;j++)
		{
			js=js&a[j];
		}
		if(js>maxn)
		maxn=js;
	}
	cout<<maxn;
	return 0;
}
