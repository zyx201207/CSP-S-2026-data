#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n;
ll sum,ans;
ll a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>a[i]>>c[i];
	int cnt1 = 1,cnt2 = n;
	while(cnt1 < cnt2){
		if(c[cnt1] != c[cnt2]){
			if(a[cnt1] == 0 || a[cnt2] == 0)
				continue;
			if(a[cnt1] >= a[cnt2]) ans += a[cnt2],a[cnt1] -= a[cnt2],a[cnt2] = 0;
			else ans += a[cnt1],a[cnt2] -= a[cnt1],a[cnt1] = 0;
			if(a[cnt1] == 0) cnt1++;
			if(a[cnt2] == 0) cnt2--;
		}else{
			if(a[cnt1] >= a[cnt2]) a[cnt1] -= a[cnt2],a[cnt2] = 0;
			else a[cnt2] -= a[cnt1],a[cnt1] = 0;
			if(a[cnt1] == 0) cnt1++;
			if(a[cnt2] == 0) cnt2--;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
