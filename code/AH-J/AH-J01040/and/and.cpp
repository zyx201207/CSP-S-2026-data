#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+10;
int n,m,arr[N],flag[N],maxn=-1;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>arr[i];
	sort(arr+1,arr+n+1);
	int flag1=1;
	for(int i=2;i<=n;i++){
		if(arr[i]!=arr[i-1]*2+1&&arr[i]!=arr[i-1]) flag1=0;
	}
	if(flag1==1){
		int yh=arr[n];
		for(int i=n-1;i>=n-m+1;i--){
			yh&=arr[i];
		}
		cout<<yh;
	}
	else if(m==1) cout<<arr[n];
	else if(m==n){
		int k=arr[1];
		for(int i=2;i<=n;i++) k&=arr[i];
		cout<<k;
	}
	else{
		int maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) maxn=max(maxn,arr[i]&arr[j]);
			}
		}
		cout<<maxn;
	}
	return 0;
}
