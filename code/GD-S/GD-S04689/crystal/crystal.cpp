#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;
int a[signed(5e5+10)];
int s[signed(5e5+10)];
signed main()
{
	ios::sync_with_stdio(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		s[i]=a[i]-a[i-1]; 
	}
	
	int ans=0,sum=0;
	for(int i=2,j=2;j<=n && i<=j ;j++)
	{
	//	cout<<i<<" "<<j<<" "<<sum<<" "<<ans<<endl;
		sum+=s[j]+(j-1-i+1)*s[j];
		//cout<<"cuh "<<i<<" "<<j<<" "<<sum<<" "<<ans<<endl;
		if(sum<=m){
		//	cout<<"ccc"<<i<<" "<<j<<" "<<sum<<" "<<ans<<endl;
		    ans=max(ans,j-i+2);	
		}
		while(sum>m){
			sum-=(a[j]-a[i-1]);
			i++;
			if(i==j)break;
		}	
	}
	cout<<ans<<endl;
	return 0; 
}
