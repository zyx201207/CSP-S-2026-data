#include<bits/stdc++.h>
using namespace std;
long long int a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long int n,m,js=0,zj=-1;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	long long int mm=m,l=n-1,f=n-1;
	for(int i=n-1;i>=0;i--)
	{
		if(mm>=a[l]-a[i])
		{
			f=i;
			mm=mm-a[l]+a[i];
			js++;
			zj=max(zj,js);
		}else if(mm+(a[l]-a[l-1])*(l-f)>=a[l-1]-a[i]){
			mm=mm+(a[l]-a[l-1])*(l-f)-a[l-i]+a[i];
			f=i;
			l--;
		}else{
			zj=max(zj,js);
			js=0;
			f=i;
			l=i;
			mm=m;
		}
	}
	cout<<zj;
	return 0;
}
