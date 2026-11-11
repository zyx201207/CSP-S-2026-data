#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int n,ans=0,k=0;
long long m,p;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	p=0;
	 for(int i=1;i<=n;i++)
	 {
	 	cin>>a[i];
	 	
	 }
	 sort(a+1,a+n+1);
     for(int i=1;i<=n;i++)
     {
     		 
     	for(int j=1;a[j+1]-a[j]+p<=m&&j<i;j++)
     	{
     		ans=j;
     		p=p+a[j+1]-a[j];
		 }
		 p=0;
        k=max(ans,k);
        
	 }
	 cout<<k+1;
	return 0;
}
