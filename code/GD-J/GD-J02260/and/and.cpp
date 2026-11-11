#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[200005];
string b[200005];
int vis[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin >> n >> m;
	int mat = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		int h = a[i];
		while(h){
			b[i] = char(h%2+48) + b[i];
			h/=2;
		}
		mat = max(mat,(int)b[i].length());
	}
	for(int i = 1;i <= n;i++){
		for(int j = b[i].length();j <= mat-1;j++){
			b[i] = '0'+b[i];
		}
	}
	int ans = 0;
	int flag = 0;
	for(int i = 0;i < mat;i++){
		int q = 0;
		for(int j = 1;j <= n;j++){
			if(b[j][i] == '1'){
				if(!flag || vis[j]){
					q++;
				}
				if(!flag){
					vis[j] = 1;
				}
			}else{
				vis[j] = 0;
			}
		}
		if(q >= m){
			for(int j = 1;j <= n;j++){
				if(b[j][i] != '1'){
					vis[j] = 0;
				}
			}
			flag = 1;
			ans+=pow(2ll,mat-i-1ll);
		}
	}
	cout << ans;
	return 0;
} 
