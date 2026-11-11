#include <bits/stdc++.h>
using namespace std;
string a[200005];
int main(){
	int n,m;cin >> n >> m;
	int cnt=0;
	for(int i=0;i<n;i++){
		int x;cin >> x;
		if(cnt==0){
			cnt+=x;
		}
		cnt+=cnt&x;
	}
	cout << cnt;
	return 0;
}