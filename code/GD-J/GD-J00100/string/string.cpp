#include <bits/stdc++.h>
using namespace std;
#define int long long
struct str{
	int num;
	char c;
}a[200005],b[200005];
int n;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i].num >> a[i].c;
		b[i].num = a[i].num;
		b[i].c = a[i].c;
	}
	reverse(a+1,a+n+1);
	bool f = 1;
	for(int i = 1;i <= n;i++){
		if(a[i].c != b[i].c){
			f = 0;
		}
	}
	if(f){
		cout << 0;
		return 0;
	}
	int i = 1,j = 1,cnt = 0;
	while(i <= n && j <= n){
		if(a[i].num >= b[j].num){
			if(a[i].c != b[j].c){
				cnt += b[j].num;
			}
			a[i].num -= b[j].num;
			j++;
		}else{
			if(a[i].c != b[j].c){
				cnt += a[i].num;
			}
			b[j].num -= a[i].num;
			i++;
		}
	}
	cout << cnt / 2;
	return 0;
}

