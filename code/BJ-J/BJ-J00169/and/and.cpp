#include<bits/stdc++.h>
#define int long long

using namespace std;

int a[200007];

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ma=0;
	cin >> n >> m;
	for(int i=1;i<=n;++i) {cin >> a[i];ma = max(ma,a[i]);}
	if(n<=20){ // 状态压缩 25 pts
		int ans = 0;
		for(int i=0;i<(1<<n);++i){
			int num=0,an = (1<<31)-1;
			for(int j=0;j<n;++j){
				bool fl = (i>>j)&1;
				if(fl) an &= a[j+1],num++;
			}
			if(num != m) continue;
			ans = max(ans,an);
		}
		cout << ans;
		return 0;
	}
	else if(m==1){
		int ans=0;
		for(int i=1;i<=n;++i) ans = max(ans,a[i]);
		cout << ans;
		return 0;
	}
	else if(m==2){
		int ans=0;
		for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j) ans = max(ans,a[i]&a[j]);
		cout << ans;
		return 0;
	}else if(m==n){
		int ans = (1<<31)-1;
		for(int i=1;i<=n;++i){
			ans &=a[i];
		}
		cout << ans;
		return 0;
	}else if(ma<4){
		int hs[4]={0};
		for(int i=1;i<=n;++i) hs[a[i]]++;
		if(m<=hs[3]) cout  << 3;
		else if(m<=hs[3]+max(hs[2],hs[1])) cout << (hs[2]>hs[1]?2:1);
		else cout << 0;
		return 0;
	}else{
		sort(a+1,a+n+1);
		int ans = (1<<31)-1;
		for(int i=n;i>n-m;--i){
			ans&=a[i];
		}
		cout << ans;
		return 0;
	}
}
