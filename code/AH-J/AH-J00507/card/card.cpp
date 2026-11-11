#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005];
ll cnt[500005];
bool k[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i<n;i++)cin >> a[i];
	for(int i = 1;i<=n;i++){
		for(int j = i-1;j<n;j++){
			if(k[j] == 1){
				for(int o = j;o>=i-1;o++){
					k[a[o]] = 0;
				} 
			}else{
				k[j] = 1;
			}
		}
		for(int j = i-1;j<m;j++){
			if(k[j] != 0)cnt[a[j]]++;
		}
	}
	for(int i = 0;i<m;i++){
		cout << cnt[i] << " ";
	}
	return 0;
}
