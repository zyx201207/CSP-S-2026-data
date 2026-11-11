#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],f[500005],ans=-1,op;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(i>2&&abs(a[i-1]-a[i-2])!=abs(a[i]-a[i-1]))op=1;
	}sort(a+1,a+n+1);
	if(!op){
		ans=1;
		for(int i=n-1;i>=1;i--){
			if(m>=ans*(a[2]-a[1])){
				m-=ans*(a[2]-a[1]);ans++;
			}
		}cout << ans;
	}else{
		for(int i=1;i<=n;i++){
			int cnt=0,v=m;
			for(int j=i;j>=1;j--){
				if(v>=abs(a[i]-a[j]))cnt++,v-=abs(a[i]-a[j]);
			}ans=max(ans,cnt);
		}cout << ans;		
	}

	return 0;
}
