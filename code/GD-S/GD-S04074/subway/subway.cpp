#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
int k,t[10005][10005],l,r,v[500005];
long long sum;
bool a[10005][10005];
int finnd(int x,int y){
	for(int j = 1;j <= n;j++){
		if(a[2][r]) 
		return t[1][j]+t[2][j];
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
		cin >> w[i];
	memset(a,0,sizeof(a));
	for(int i = 1;i <= n;i++){
		cin >> k;
		for(int j = 1;j <= k;j++){
			int x,y;
			cin >> x >> y;
			a[i][x] = 1;
			t[i][x] = y;
			v[x]++;
		}
	}cout << 1 << endl;
	for(int i = 1;i <= q;i++){
		sum = 0;
		cin >> l >> r;
		sum += w[l]+w[r];
		bool flag = 0;
		for(int j = 1;j <= n;j++){
			if(a[j][l]&&a[j][r]){
				sum+=t[j][l]+t[j][r];
				cout << sum << endl;
				flag = 1;
				break;
			}
		}if(flag) continue;
		for(int j = 1;j <= n;j++){
			if(v[j] > 1&&a[1][j]){
				sum += t[1][l]+t[1][j]+t[2][j]+t[2][r];
				break;
			}
		}cout << sum << endl;
	}return 0;
}
