#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],t[200005],cnt,ans,c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n<=5000){
		ll kk=m;
		sort(a+1,a+n+1);
		for(int i=1;i<n;i++)a[i]=a[i+1]-a[i];
		for(int j=1;j<n;j++){
			ans=1;
			m=kk;
			for(int i=j;i<n;i++){
				if(m-a[i]*(i-j+1)>=0){
					m-=a[i]*i;
					ans++;
				}else{
					break;
				}
			}
			cnt=max(cnt,ans);
		}	
		cout<<cnt;
	}
	else{
		sort(a+1,a+n+1);
		for(int i=1;i<n;i++)a[i]=a[i+1]-a[i];
		for(int i=1;i<n;i++){
			if(m-a[i]*i>=0){
				m-=a[i]*i;
				ans++;
			}else{
				break;
			}
		}
		cout<<ans;
	}
	return 0;
}//75fen
/*
5 5
1 2 4 8 9
------------
5 8
-3 -1 2 2 7
*/

