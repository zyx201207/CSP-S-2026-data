#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500000];
int js[300000],b[300000];
int p[500000];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			p[j] = 0;
		}
		int t = 0;
		for(int j = i;j <= n;j++){
			for(int k = 1;k <= t;k++){
				if(a[j] == p[k]){
					for(int l = k;l <= t;l++){
						p[l] = 0;
					}
					t = k - 1;
				}
			}
			p[++t] = a[j];
		}
		cout<<t<<endl;
		for(int j = 1;j <= t;j++){
			cout<<p[i]<<' ';
		}
		cout<<endl;
		for(int j = 1;j <= m;j++){
			if(b[i] != 0){
				js[i]++;
			}
		}
	}
	return 0;
}
