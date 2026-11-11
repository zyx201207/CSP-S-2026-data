#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],x,s;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {cin>>a[i]>>b[i];x+=a[i];}
	for(int i=1,j=n;i<=n/2; )
	{
		if(b[i]!=b[j])
		{
			if(a[i]<a[j]) a[j]-=a[i],s+=a[i],i++;
			else if(a[i]>a[j]) a[i]-=a[j],s+=a[j],j--;
			else s+=a[i],i++,j--;
		}
		else
		{
			if(a[i]<a[j]) a[j]-=a[i],i++;
			else if(a[i]>a[j]) a[i]-=a[j],j--;
			else s+=a[i],i++,j--;
		}
	}
	cout<<s;
	return 0;
} 
