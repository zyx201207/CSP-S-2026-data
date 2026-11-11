#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],cc,cc1,cc2,s;
char b[200005];
string summ;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		for(int j=0;j<a[i];j++)
		{
			summ+=b[i];
			cc++;
		}
	}
	cc1=cc/2;
	for(int i=0,j=cc-1;i<j;i++,j--)
	{
		if(summ[i]!=summ[j])
		{
			s++;
		}
	}
	cout<<s;
	return 0;
} 
