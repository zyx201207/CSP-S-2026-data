#include<bits/stdc++.h>
#include<string.h>
using namespace std;
const int N=2e5;
int a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==2){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)
		{
			if((a[i]&a[j])>=maxn)	maxn=(a[i]&a[j]);
		}
	}	
	cout<<maxn;
	return 0;
	}
	if(m==n){
		maxn=a[1];
		for(int i=2;i<=n;i++)
		maxn=(maxn&a[i]);
		cout<<maxn;
		return 0;
	}
	if(m==1)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j]>=maxn)	maxn=a[j];
		}
		cout<<maxn;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++)
		{
			if((a[i]&a[j])>=maxn)	maxn=(a[i]&a[j]);
		}
	}
	cout<<maxn;
	return 0;
}
