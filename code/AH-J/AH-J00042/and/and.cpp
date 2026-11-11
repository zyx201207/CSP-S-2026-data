#include<bits/stdc++.h>
using namespace std;
int m,n,x,t=1,y,max;
int a[10000005],b[10005];
int main()
{
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
	b[i]=a[i];
	for(int j=1;j<=i;j++){
		if(b[j]==a[i]){
			cout<<b[i];
			return 0;
		}
	}
}
sort(a+1,a+n+1);
int l=n/2;
cout<<a[l];
fclose(stdin);
fclose(stdout);
return 0;
}
