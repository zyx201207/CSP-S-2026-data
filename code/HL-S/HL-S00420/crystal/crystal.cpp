#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;cin >> n >> m;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	int sum = 0;
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++){
		int ct = 0;
		
		for(int j = 1;j < i;j++){
			ct += a[i] - a[j];
			if(ct > m){
				cout << sum;
				return 0;
			}
			sum++;
		}
	}
	cout << sum;
	return 0;
}