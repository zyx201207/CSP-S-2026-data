//GZ-J00368 贵阳市第三十三中学 叶发睿 
#include<bits/stdc++.h>
using namespace std;

const int N = 2e6+10;
int n, m, a[N], s[N], b[N];
int cnt = 0;

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	int l = 1, r = n;
	while(n--){
		for(int i = 1; i <= n; i++){
			s[i] = a[i];
			if(s[i] == a[i]){
				r = i;
				int mid = (r+l)/2;
				l = 0;
				mid = 0;
			}
			l = r;
			r = n;
			if(s[i] == a[i]){
				b[i]++;
			}
			s[i] = 0;
		}
	}
	
	for(int i = 1; i <= m; i++){
		cout << b[i] << " ";
	}
	return 0;
}
