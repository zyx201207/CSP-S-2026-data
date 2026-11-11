#include<bits/stdc++.h>
using namespace std;
long long a[35]={},site,site_m;int b[2*100000+5];
bool flag;
long long m,n,c,ans;
bool cmp(long long a,long long b){
	return a>b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>m>>n;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	sort(a,a+m,cmp);	
	long long ans=a[0];
	for(int i=1;i<n;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
