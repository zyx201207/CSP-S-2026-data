#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 + 10;
int n;
ll a[N],ans = 0,m,d[N],x;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	x = a[n];
	if(n <= 5000){
		for(int i = 1;i <= n;i++){
			ll k = m,cnt = 1;
			for(int j = i - 1;j >= 1;j--){
				ll x = abs(a[i] - a[j]);
				if(k - x >= 0){
					k -= x;
					++cnt;
				}else break;
			}
			ans = max(ans,cnt);
		}
		cout << ans;
	}
	else{
		for(int i = 1;i <= n;i++)
			d[i] = x - a[i];
		for(int i = n - 1;i >= 1;i--)
			d[i] = d[i] + d[i + 1];
		for(int i = n;i >= 1;i--){
			if(d[i] > m) break;
			++ans;
		}
		cout << ans;
	}
	return 0;
}
/*
那是我日夜思念深深爱着的人啊，叫我该如何去表达，她会接受我吗，也许我永远都不会说出那句话，我注定该浪迹天涯，怎么能有牵挂，梦想总是遥不可及，是不是应该放弃，花开花落又是一季，春天啊你在哪里？
*/