#include <bits/stdc++.h>
using namespace std;
long long a[100100];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	long long num=0;
	for(long long i=0;i<n-m+1;i++)
	{
		long long max1=a[i];
		for(long long j=i;j<i+m;j++)
		{
			long long aj=a[j];
			max1=max1&aj;
		}
			num=max(num,max1);
	}
	cout<<num;
	return 0;			
}
