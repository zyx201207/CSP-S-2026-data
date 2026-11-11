#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
struct Node{
	int a;
	char c;
}b[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	long long s = 0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> b[i].a >> b[i].c;
		s += b[i].a;
	}
	long long aa = 1, cc = 1, aaa = 1, ccc = n;
	long long ans = 0;
	for(long long i=1;i<=s/2;i++){
		if(b[cc].c!=b[ccc].c){
			ans++;
		}
		if(b[cc].a==aa){
			aa = 1;
			cc++;
		}else{
			aa++;
		}
		if(b[ccc].a==aaa){
			aaa = 1;
			ccc--;
		}else{
			aaa++;
		}
	}
	cout << ans;
	return 0;
}
