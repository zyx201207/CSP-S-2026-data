#include<bits/stdc++.h>
using namespace std;
long long n,p,h=1,ans;
char a[1000000],pp;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p>>pp;
		p=h+p;
		for(int j=h;j<=p;j++)
		{
			a[j]=pp;
		}
		h=p;
	}
	for(int i=1;i<=h;i++)
	{
		if(a[i]!=a[h+1-i])
		{
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
