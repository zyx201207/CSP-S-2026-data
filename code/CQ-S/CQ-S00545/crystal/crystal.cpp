#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m;
const int maxn = 5e5 + 10;
ll a[maxn],s[maxn];
//

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i] = s[i-1] + a[i];
	int pos = 1;
	int ans = 0;
	for(int i=1;i<=n;i++){
		while(pos < i && a[i] * (i-pos+1) - (s[i] - s[pos-1]) > m) pos++;
		ans = max(ans,i-pos+1);
	}
	cout<<ans;
	return 0;
}

