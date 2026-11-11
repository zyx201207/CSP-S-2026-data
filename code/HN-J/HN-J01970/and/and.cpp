#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
int cnt=INT_MIN;
signed main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=m+1;j<=n;j++){
			int y=0;
			for(int l=i;l<=j;l++){
				y^=a[i];
			}
			cnt=max(y,cnt);
		}
	}
	cout<<cnt;
	return 0;
}
