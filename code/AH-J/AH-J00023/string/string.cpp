#include<bits/stdc++.h>
using namespace std;
int a[200005];
long long b[200005],cnt; 
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		b[i]=b[i-1]+a[i];	
	}
	for(int i=1,j=1;i<=n-i+1;j++)
	{
		if(b[i]-j==0)i++;
		if(c[i]!=c[n-i+1])cnt++;
	}
	cout<<cnt;
	return 0;
}
