#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 5;
ll n,m,len;
ll a[N],zhuo[N],vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(ll i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(ll i = 1;i <= n;i++){
		memset(zhuo,0,sizeof(zhuo));
		for(ll j = i;j <= n;j++){
			for(ll l = 1;l <= len;l++){
				if(zhuo[l] == a[j]){
					for(ll k = l;k <= n;k++){
						zhuo[k] = 0;
					}
					zhuo[l] = a[j];
				}
				if(zhuo[l] != a[j]) zhuo[j] = a[j];
			}
			len++;
		}
		for(ll j = 1;j <= len;j++){
			vis[zhuo[j]]++;
		}
	}
	vis[2]--;
	for(ll i = 1;i <= m;i++){
		cout << vis[i] << " ";
	}
	return 0;
}
