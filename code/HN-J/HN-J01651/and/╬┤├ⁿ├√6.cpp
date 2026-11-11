#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int sum[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>sum[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			x=sum[j]^=sum[j+1];
		}
	}
	cout<<x;
	return 0;
} 
