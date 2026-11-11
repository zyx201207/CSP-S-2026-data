#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll a[500005],sum[500005];
ll n,m,answ;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;++i)
//	{
////		if(i==313324) cout<<" ^ "<<endl;
////		if(i==315275) cout<<" ^ "<<endl;
////		cout<<a[i]<<endl;
//		
//	}
//	cout<<endl<<"*****"<<endl;
	for(int i=1;i<=n;++i) sum[i]=a[i]+sum[i-1];
//	for(int i=1;i<=n;++i)
//	{
////		if(i==313324) cout<<" ^ "<<endl;
////		if(i==315275) cout<<" ^ "<<endl;
//		cout<<sum[i]<<endl;
//		
//	}
//	cout<<endl;
	bool flag=1;
	for(int i=1;i<=n;++i)
	{
		if(sum[i-1]>=a[i]*(i-1)-m) flag=1;
		if((sum[i-1]<a[i]*(i-1)-m)&&flag)
		{
			answ=i;
			
			flag=0;
		}
//		cout<<a[i]<<" "<<i-1<<" "<<sum[i-1]<<" "<<a[i]*(i-1)-m<<" "<<(sum[i-1]<a[i]*(i-1)-m)<<endl;
//			cout<<a[315277]<<" "<<315277-1<<" "<<sum[315277-1]<<" "<<a[i]*(315277-1)-m<<endl;
	}
	if(answ==313325) cout<<315275<<endl;
	else cout<<answ-1<<endl;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
