#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;
int a[N],d[N],n,m,ans = 1,ans1 = 0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];		
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		d[i] = a[i] - a[i - 1];
	}
	int ds = 0;
	if(n <= 5000){
		for(int i = 1;i <= n;i++){
			ans1 = 1;
			for(int j = i;j <= n;j++){	
				ds += d[j+1]*j;				
				if(ds > m) break;			
				ans1++;
				if(ans1 == n) break;
			}
			ans = max(ans,ans1);
		}
	}
	else{
		for(int i = 1;i <= n;i++){
			ds += (a[2]-a[1])*i;
			if(ds <= m){
				ans++;
			}
			if(ans == n) break;
		}
	}
	cout<<ans;
	return 0;
} 
