#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[29999999],c[29999999];
signed main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n,m,i,k,sum=1;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n%2==0)
		k=a[n/2];
	else{
		k=a[n/2+1];
	}
	for(i=1;i<=n;i++)
	{
		c[i]=abs(k-a[i]);
	}
	sort(c+1,c+n+1);
	for(i=2;i<=n;i++)
	{
		if(m<c[i])
		{
			break;
		}
		m-=c[i];
		sum++;
	}
	cout<<sum;
	return 0;
} 
