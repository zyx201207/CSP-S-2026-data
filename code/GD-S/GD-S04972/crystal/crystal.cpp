#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1000005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=m;
	for(int i=1;i<=n;i++){
		ans+=a[i];
		if(ans/i==a[i]){
			for(int j=i;j<=n;j++){
				if(a[j+1]==a[j]){
					cout<<i+j;
					return 0;
				}
			}
			cout<<i;
			return 0;
		}
	}
	return 0;
} 
