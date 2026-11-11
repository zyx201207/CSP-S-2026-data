#include<iostream>
using namespace std;
#define ll long long
#define N 200005
ll n;
struct S{
	ll a, st;
	char c;
}s[N];
ll ans = 0;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	s[0].a=1;
	s[0].st=0;
	for(int i = 1;i <= n;i++){
		cin >> s[i].a >> s[i].c;
		s[i].st = s[i-1].st+s[i-1].a;
	}
	ll i = 0,j = 0, u = 1, v = n;//u, v已经用了的字符长度i, j 
	while(u < v){
		ll l;
		
		if(s[u].a-i < s[v].a-j){
			l = s[u].a - i;
			if(s[u].c != s[v].c)ans += l;
			if(s[u].a-i+j<s[v].a){
				j += s[u].a-i;
			}
			else{
				v--;
				j = 0;
			}
			i = 0;
			u++;
		}else{
			l = s[v].a - j;
			if(s[u].c != s[v].c)ans += l;
			if(i+s[v].a-j<s[u].a){
				i += s[v].a-j;
			}
			else{
				u++;
				i = 0;
			}
			j = 0;
			v--;
		}
		/*if(s[u].c != s[v].c){
			ans += l;
		}*/
	}//加油！ 
	cout << ans << endl;
	return 0;
}
