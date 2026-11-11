#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
struct Info{
	int num;
	char st;
} op[200101];
char s[50000001];
int lenop2 = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> op[i].num >> op[i].st;
		for(int j = 1;j <= op[i].num;j++){
			s[++lenop2] = op[i].st;
		}
	}
	if(lenop2 % 2 == 0){
		lenop2 /= 2;
		int ans = 0;
		for(int i = lenop2,j = lenop2 + 1;i >= 1 && j <= lenop2 * 2;i--,j++){
			if(s[i] != s[j])
				ans++;
		}
		cout << ans;
	}else{
		int cnt = lenop2 / 2 + 1;
		int ans = 0;
		for(int i = cnt - 1,j = cnt + 1;i >= 1 && j <= lenop2;i--,j++){
			if(s[i] != s[j]){
				ans++;
			}
		}
		cout << ans;
	}
	return 0;
}
