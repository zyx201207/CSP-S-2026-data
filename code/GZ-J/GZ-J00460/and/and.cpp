//GZ-J00460 贵阳市第十七中学 徐廷蔚
#include<bits/stdc++.h>
using namespace std;
vector<int>w[200005];
vector<int>co[200005];
int a[200005];
int n,m;
long long s[50];
long long ans;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
		int tmp = a[i];
		int cnt = 1;
		for(;cnt <= 29;cnt ++) {
			w[i].push_back(tmp%2);
			if(w[i][cnt] > 1)w[i][cnt] = 0;
			tmp >>= 1;		
		}
		co[i].push_back(0);
	}
	for(int i = 1;i <= n;i ++) {
		for(int b = 0;b <= 29;b ++){
			s[b] = s[b] + w[i][b];
		}
	}
	int checkb = 0;
	for(int b = 29;b >= 0;b --) {
		if(s[b] < m) continue;
		if(s[b] == m) {
			int cnt = 1;
			for(int i = 1;i <= n;i ++) {
				if(w[i][b] == 1) {
					w[cnt] = w[i];
					cnt ++; 
				}
			}
			n = cnt - 1;	
			break;
		}
		if(s[b] > m) {
			int cnt = 1;
			for(int i = 1;i <= n;i ++) {
				if(w[i][b] == 1) {
					co[cnt] = w[i];
					cnt ++; 
				}
			}
			for(int i = 1;i < cnt;i ++){
				w[i] = co[i];
			}
			n = cnt - 1;
			memset(s,0,sizeof s);
			for(int i = 1;i <= n;i ++) {
				for(int k = 0;k <= 29;k ++){
					s[k] = s[k] + w[i][k];
				}
			}			
		}
	}
	for(int i = 1;i <= n;i ++){
		long long tmp = 0;
		for(int b = 0;b <= 29;b ++) {
			tmp |= ((long long)w[i][b] << (b));
		}
		if(i == 1)ans = tmp;
		else ans &= tmp;
	}
	cout<<ans;
	return 0;
}
