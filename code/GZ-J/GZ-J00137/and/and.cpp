#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin >> n >> m;
	int maxx = -1;
	int a;
	for(int i = 0;i<n;i++){
		cin >> a;
		if(a>maxx)maxx=a;
	}
	cout << maxx;
	return 0;
}

