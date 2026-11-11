#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		string c;
		cin>>c;
		for(int j=1;j<=a;j++){
			S=S+c;
		}
	}
	return 0;
}
