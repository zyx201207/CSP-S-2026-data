//华东师范大学附属贵阳学校 陈睿阳 GZ-J00418 
#include <bits/stdc++.h>
using namespace std;
const int N=1e9+10;
int n,x;
char a[N];
char y;
int cnt=0,qh=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	string s;
	for (int i=1;i<=n;i++){
		cin >> x >> y;
		for (int j=qh+1;j<=qh+x;j++){
			a[j]=y;
		}
		qh+=x;
	}
	for (int i=1;i<=qh/2;i++){
		if (a[i]!=a[qh+1-i]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
