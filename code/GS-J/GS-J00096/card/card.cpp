#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[300010],c[500010],f[300010],p[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		memset(f,0,sizeof(f));
		memset(c,0,sizeof(c));
		for(int j = i;j <= n;j++){
			c[j] = a[j];
			if(!f[a[j]]){
				f[a[j]] = 1;
				p[a[j]] = j;
			}
			else{
				for(int k = p[a[j]];k < j;k++){
					if(k == p[a[k]]){
						f[a[k]] = 0;
					}
					c[k] = 0;
				}
				p[a[j]] = j;
				f[a[j]] = 1;
			}
		}
		for(int j = i;j <= n;j++){
			if(f[a[j]]){
				b[a[j]]++;
				f[a[j]] = 0;
			}
		}
	}
	b[a[n]] = n;
	for(int i = 1;i <= m;i++){
		cout << b[i] << ' ';
	}
	return 0;
}
