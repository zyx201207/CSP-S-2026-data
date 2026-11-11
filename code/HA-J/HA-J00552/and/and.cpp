#include<bits/stdc++.h>//&га0ЮЊ0 
using namespace std;
int a[200010],s[200010],n,m,sum=pow(2,31)-1;
bool cpcp(int xx,int yy)
{
	return xx>yy;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cpcp);
	for(int i=1;i<=m;i++)
		sum&=a[i];
	cout<<sum;
	
	
	return 0;
}
