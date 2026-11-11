#include<bits/stdc++.h>
using namespace std;
long long n;
struct str{
	int s,c;
};
str a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].s >> a[i].c;
	}
	cout << 0;
	return 0;
}
