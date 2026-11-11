#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int f(int a,int b){
	string sa,sb,s;
	int ans=0;
	while(a)
	{
		if(a%2==0)  sa+='0';
		else  sa+='1';
		a/=2; 
	}
	while(b)
	{
		if(b%2==0)  sb+='0';
		else  sb+='1';
		b/=2; 
	}
	for(int i=0;i<=min(sa.size(),sb.size())-1;i++)
	{
		if(sa[i]=='1'&&sb[i]=='1')  s+='1';
		else  s+='0';
	}
	for(int i=0;i<=s.size()-1;i++)
	{
		int t=pow(2,i);
		if(s[i]=='1')  ans+=t;
	}
	return ans;
}
long long n,m,a[200005],b[200005],maxx=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)  cin>>a[i];
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)  b[i]=a[i];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<=n-i-1;j++)
		{
			b[j]=f(b[j],a[j+i+1]);
			if(b[j]>maxx)  maxx=b[j];
		}
	}
	cout<<maxx;
	return 0;
}
