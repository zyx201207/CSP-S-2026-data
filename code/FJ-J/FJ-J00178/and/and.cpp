#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
int n,m,a[N],cnt[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	vector<int> b[30];
	for(int i=0;i<30;i++){
		for(int j=1;j<=n;j++){
			if((a[j]>>i)&1) b[i].push_back(j);
		}
	}
	vector<bool> c(n+1,1);
	int ans=0;
	for(int i=29;i>=0;i--){
		if(b[i].size()<m) continue;
		int cnt=0;
		for(int x:b[i]){
			if(c[x]) cnt++;
		}
		if(cnt<m) continue;
		ans+=1<<i;
		vector<bool> d(n+1,0);
		for(int x:b[i]) d[x]=1;
		for(int j=1;j<=n;j++) c[j]=c[j]&d[j];
	}
	cout << ans;
	return 0;
}
