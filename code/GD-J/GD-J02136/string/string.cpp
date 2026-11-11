#include<bits/stdc++.h>
using namespace std;

int n, cnt;
struct node{
	int m;
	char c;
}a[200005];
string s;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i].m >> a[i].c;
		s.append(a[i].m, a[i].c);
	}
	int z=s.size();
	for(int i=0; i<=z/2-1; i++){
		if(s[i]!=s[z-1-i]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
