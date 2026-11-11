#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,l,r,x,ans,cnt,t[200010];
bool a[40][200010];
vector<int> kx;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
		cin >> x;
		int cnt=1;
		while(x!=0){
			a[cnt][i]=x%2;
			x/=2;
			cnt++;
		}
		kx.push_back(i);
	}
	for(int i=30;i>=1;i--){
		cnt=0;
		for(auto j:kx){
			if(a[i][j]==1) cnt++;
		}
		if(cnt>=m){
			vector<int> ky;
			for(auto j:kx){
				if(a[i][j]==1) ky.push_back(j);
			}
			kx=ky;
			ans+=1<<(i-1);
		}
	}
	cout << ans;
    return 0;
}
