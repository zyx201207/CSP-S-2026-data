#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100001],b[10001],t,mi;
bool cmp(int a,int b)
{
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<m;i++)
	{
		if(a[i]<a[mi])mi=i;
	}
	cout<<a[mi];
	return 0;
} 
