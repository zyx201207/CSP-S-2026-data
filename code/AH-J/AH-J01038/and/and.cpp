#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=-1,c,d;
long long a[200010],b[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}sort(a+1,a+1+n);
	if(m==1)
	{
		cout<<a[n];
		return 0;
	}
	else if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
		b[i]=a[i]&a[i+1];
		maxn=max(maxn,b[i]);
		
	}
	cout<<maxn;
	return 0;
}
else if(m==n){
	long long k;
	for(int i=2;i<=n;i++){
		k=a[1];
		k&=a[i];
	}cout<<k;
}
	

	return 0;
}
