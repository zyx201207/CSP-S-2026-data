#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],sum,r,t;
char b[100005];
string s;
int main(){
//freopen("string.in","r",stdin);
//freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++)
{
	cin>>a[i]>>b[i];
} 
if(n%2==0)
{
	r=n/2;
	t=r;	
}	
else
{
	r=n/2+1;
	t=r-1;
}
for(int j=r+1;j<=n;j++)
{
	if(b[t]!=b[j])
	{
		sum+=a[j];
	}
	t--; 
}
cout<<sum;
	return 0;
}

