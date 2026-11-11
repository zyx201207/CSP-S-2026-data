#include<bits/stdc++.h>
#define int long long

using namespace std;

int n,m;
int a[500005],b[500005];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i = 1;i<=n;i++){
		b[i] = b[i-1]+a[i];
	}
	int ans = 0,cnt = 0;
	for(int l = 1,r = 2;r<=n;r++){
		int len = r-l+1;
		cnt = a[r]*len-(b[r]-b[l-1]);
		while(cnt>m && l<r){
			l++;
			len = r-l+1;
			cnt = a[r]*len-(b[r]-b[l-1]);
		}
		ans = max(ans,r-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
//ypy is so cute
//cq-j00585 && cq-s00583
