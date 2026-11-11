#include<bits/stdc++.h>
using namespace std;
int a[2000010];int n,d,cnt,ans,ch;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
int c,t;
cin>>c>>t;
while(t--)
{
cin>>n>>d;
for(int i=0;i<=1001;i++) a[i]=0;
for(int i=1;i<=n;i++) cin>>a[i];

cnt=0;
sort(a+1,a+n+1);
ch=a[2]-a[1];
 for(int i=1;i<=n;i++)
 { 
	for(int j=i+1;j<=n;j++)
	{
	if(a[j]-a[i]>d&&a[j]-a[i]<2*d) cnt++;
	}
 }
 cout<<cnt<<endl;
}
}
