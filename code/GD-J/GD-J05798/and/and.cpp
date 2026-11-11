#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],maxx=0,mbxx=0,ssss;
long long yu(long long x,long long  y){
	string s,k;
	long long q=0;
    for(int i=30;i>=0;i--)
    {
    	long long p=pow(2,i);
    	if(x>=p) s+='1',x-=p;
    	else s+='0';
	}
	//cout<<s<<"\n";
	for(int i=30;i>=0;i--)
	{
		long long p=pow(2,i);
		if(y>=p) k+='1',y-=p;
		else k+='0';
	}
	//cout<<k<<"\n";
	for(int i=0;i<=30;i++)
	{
		long long p=pow(2,i);
		//cout<<p<<" ";
		if(s[30-i]=='1'&&k[30-i]=='1')
		{
			q+=p;
			//cout<<'l'<<"\n";
		}
	}
	//cout<<q<<" ";
	return q;
}
long long pow(int r,int l){
	long long j=1;
	for(int i=1;i<=l;i++)
	{
		j*=2;
	}
	return j;
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
	ssss=a[n];
	for(int i=n;i>=n-m+1;i--)
	{
		ssss=yu(ssss,a[i]);
		if(i-1<n-m+1) {
		if(ssss==0) cout<<a[i];
		else	
		cout<<ssss;	
		break;
		}
	}
	return 0;
}
