#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){                                                                                                                                             
freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		cin>>n>>m;
		for(long long i=1;i<=n;i++)cin>>a[i];
		long long cha=a[2]-a[1];
                                    if(cha>m){
                                    	cout<<1;
                                    }else if(cha==m){
                                    	cout<<2;
									}else{
										m-=cha;
									long long	ans=2;
										while(m>=ans*cha&&ans<=n){
											m-=ans*cha;
											ans++;
										}
										 cout<<ans;
									}
	return 0;
}
