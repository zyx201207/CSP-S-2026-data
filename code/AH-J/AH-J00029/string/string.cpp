#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 2;
struct node{
	int x;
	char c;
}s[maxn];
int n;
long long ans;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

	cin >> n;
    for(int i = 1; i <= n; i++)
		cin >> s[i].x >> s[i].c;
	for(int i = 1, j = n; i < j; ){
		if(i == j - 1 && s[i].c == s[j].c)
			break;
		if(s[i].c == s[j].c){
			if(s[i].x == s[j].x){
				i++;j--;
				continue;
			}
			else if(s[i].x > s[j].x){
				s[i].x -= s[j].x;
				j--;
				continue;
			}
			else{
				s[j].x -= s[i].x;
				i++;
				continue;
			}
		}
		else{
			if(s[i].x == s[j].x){
				ans += s[i].x;
				i++;j--;
				continue;
			}
			else if(s[i].x > s[j].x){
				ans += s[j].x;
				s[i].x -= s[j].x;
				j--;
				continue;
			}
			else{
				ans += s[i].x;
				s[j].x -= s[i].x;
				i++;
				continue;
			}
		}
	}
	cout << ans;
    return 0;
}
//Trick||Treat!

