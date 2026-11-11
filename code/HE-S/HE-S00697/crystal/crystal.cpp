#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000000010],ans,sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++){
		if((a[i]-a[i-1])*(i-1)<=m){
			sum=(a[i]-a[i-1])*(i-1);
			for(int j=i-1;j>=1;j--) a[j]=a[i];
			m-=sum;
		    ans=i; 
		}
	}
	cout<<ans;
	return 0;
} 

