#include<bits/stdc++.h>
using namespace std;
const int N = 25;
int x[N];
int y[N];
int n,m;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	if(n == m) cout << 1;
	else cout << 0;
	if(x[0]&x[1] == y[0]&y[1]) cout << 1;
	else cout << 0;
	if((x[2]==68&&y[2]==69)||(x[2]==69&&y[2]==70)||(x[2]==71&&y[2]==73)) cout << 11;
	else cout << 00;
	return 0;
}
