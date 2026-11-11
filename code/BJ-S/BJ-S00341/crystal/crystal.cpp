#include <bits/stdc++.h>
using namespace std;
long long a[100010],b[10010][10010];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	long long mx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		for(int j=1;j<=i;j++){
			long long mi=1e9,mx1=-1,ans=0;
			for(long long k=j;k<=i;k++){
				mi=min(mi,k);
				mx1=max(mx1,k);
				b[i][j]+=k;
				ans++;
			}
			if(mi+m>=mx1 && b[i][j]+m>=(ans*mx1)){
				mx=max(mx,ans);
			}
		}
	}cout<<mx;
	return 0;
}
