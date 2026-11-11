#include<bits/stdc++.h>
using namespace std;
long long c1[200010],n;
char a1[200010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> c1[i] >> a1[i];
	}
	int r = n,l = 1;
	long long cnt1 = 0;
	while(l < r){
		if(c1[l] > c1[r]){
			c1[l] = c1[l]-c1[r];
			if(a1[l] == a1[r]){
				r--;
			}else{
				cnt1+=c1[r];
				r--;
			}
		}else if(c1[l] < c1[r]){
			c1[r] = c1[r]-c1[l];
			if(a1[l] == a1[r]){
				l++;
			}else{
				cnt1+=c1[l];
				l++;
			}
		}else{
			if(a1[l] != a1[r]){
				cnt1+=c1[l];
			}
			l++;
			r--;
		}
	}
	cout << cnt1;
	return 0;
}
