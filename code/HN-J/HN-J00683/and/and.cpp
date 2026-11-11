#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin >> n >> m;
	int a[n];
	for(int i = 0;i < n;i++) cin >> a[i];
	if(m == 1){
		int maxx = -1;
		for(int i = 0;i < n;i++)
			if(a[i] > maxx) maxx = a[i];
		cout << maxx;
	}
	else if(m == n){
		int num = a[0];
		for(int i = 1;i < m;i++)
			num = (num & a[i]);
		cout << num;
	}
	else if(m == 2){
		int maxn = -1;
		for(int i = 0;i < n-1;i++){
			for(int j = i+1;j < n;j++){
				int x = (a[i] & a[j]);
				if(x > maxn) maxn = x;
			}
		}
		cout << maxn;
	}
	else if(m == n-1){
		int maxy = -1;
		int w[n-1];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(j == i) continue;
				w[j] = a[j];
			}
			int y = (w[0] & w[1]);
			for(int k = 2;k < n-1;k++)
				y = (y & w[k]);
			if(y > maxy) maxy = y;
		}
		cout << maxy;
	}
	return 0;
}
