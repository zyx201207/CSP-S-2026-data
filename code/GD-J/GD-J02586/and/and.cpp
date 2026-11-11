#include<bits/stdc++.h>
using namespace std;

long long n,m,cnt,q,p[200010];
long long a[2000010];

c(long long x){
	cnt=0;
	while(x/=2) cnt++;
	return cnt;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(c(a[n])==c(a[n-i])) p[i]=a[n-i];
		else if(a[n]%2==1&&a[n-i]%2==1)p[i]=a[n-i];
	}
	q=a[n];
	for(int i=1;i<m;i++)
	{
		q=(q&p[i]);
	}
	cout<<q;
	return 0;
}

