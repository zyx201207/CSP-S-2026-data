#include <bits/stdc++.h>
using namespace std;
long long n,a[200001],t1=0,sum=0;
char p[200005];
string str=" ";
int main()
{
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i]>>p[i];sum+=a[i];
	for(int j=1;j<=a[i];j++)str+=p[i];
	}
for(int i=0;i<=sum/2;i++)if(str[i]!=str[sum-2-i])t1++;
cout<<t1;
return 0;
}
