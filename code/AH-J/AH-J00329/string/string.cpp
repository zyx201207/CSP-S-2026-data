#include<bits/stdc++.h>
using namespace std;
int n;
long long ans, L, l;
struct str{
	int cnt;
	char ch;
}s[200010];
int top = 0;
str stk[200010];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> s[i].cnt >> s[i].ch;
		L += s[i].cnt;
	}
	if(L & 1){//强行删成偶数串
		int mid = (L + 1) / 2, sum = 0, cur = 0;
		while(sum < mid)sum += s[++cur].cnt;
		s[cur].cnt--, L--;
	}
	for(int i = 1;i <= n;i++){
		if(!s[i].cnt)continue;
		l += s[i].cnt;
		if(l <= L / 2)stk[++top] = s[i];
		else{
			if(l - s[i].cnt < L / 2){
				//被分成前后2段，分段分析
				str tmp;tmp.cnt = L / 2 - (l - s[i].cnt);tmp.ch = s[i].ch;
				stk[++top] = tmp;s[i].cnt -= tmp.cnt;
			}
			//分析
			if(stk[top].cnt >= s[i].cnt){
				if(stk[top].ch != s[i].ch)ans += s[i].cnt;
				stk[top].cnt -= s[i].cnt;
			}else{
				while(s[i].cnt >= stk[top].cnt){
					if(stk[top].ch != s[i].ch)ans += stk[top].cnt;
					s[i].cnt -= stk[top--].cnt;
				}
				if(s[i].cnt){
					if(stk[top].ch != s[i].ch)ans += s[i].cnt;
					stk[top].cnt -= s[i].cnt;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
