#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[500005],ans[300005];

int read(){
	int k = 0,f = 1,c = getchar();
	for(;!isdigit(c);c = getchar())
		if(c == '-')
			f = -1;
	for(;isdigit(c);c = getchar())
		k = k*10 + (c^48);
	return k * f;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);

	n = read(),m = read();
	for(int i = 1;i <= n;i++)
		a[i] = read();
	for(int i = 1;i <= n;i++){
		int f[m+5];
		for(int j = 1;j <= m;j++)
			f[j] = 0;
		for(int j = i;j <= n;j++){
			if(f[a[j]])
				for(int k = 1;k <= m;k++)
					if(f[k] > f[a[j]])
						f[k] = 0;
			f[a[j]] = j;
		}
		for(int j = 1;j <= m;j++)
			if(f[j])
				ans[j]++;
	}	
	for(int i = 1;i <= m;i++)
		cout << ans[i] << ' ';
	
	return 0;
}
