#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <cmath>
using namespace std;
#define ll long long
ll n,m;
ll a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	ll ans[300005] = {};
	for(int i = 1;i <= n;i++){
		queue<ll>s;
		bool t[300005] = {};
		for(int j = i;j <= n;j++){
			if(t[a[j]]){
				while(!s.empty()){
					t[s.front()] = false;
					s.pop();
				}
				s.push(a[j]);
			}else{
				s.push(a[j]);
				t[a[j]] = true;
			}
		}
		while(!s.empty()){
			ans[s.front()]++;
			s.pop();
		}
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}