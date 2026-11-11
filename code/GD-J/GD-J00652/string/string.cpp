#include<bits/stdc++.h>
using namespace std;
int n,a,io = 1,minn = 2e9;
char c,b[100001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a >> c;
		for(int i = 1;i <= a;i++){
			b[io] = c;
			io++;
		}
	}
	int cnt,ans = 0;
	for(int i = 1;i <= io / 2;i++){
		if((int)b[i] != (int)b[io - i]) ans++;
	}
	minn = min(ans,minn);
	ans = 0;
	if(io % 2 == 0) cnt = io / 2 + 1;
	else cnt = io / 2 + 2; 
	for(int i = cnt;i <= io;i++){
		if((int)b[i] != (int)b[io - i]) ans++;
	} 
	cout << min(minn,ans);
	return 0;
}
