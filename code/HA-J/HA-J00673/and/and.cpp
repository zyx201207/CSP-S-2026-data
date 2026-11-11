#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[200005];
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	vector<int>b;
	for(int i = 0;i < m;i++){
		b.push_back(a[i]);
	}
	int ans = b[0];
	for(int i = 0;i < m;i++){
	    ans = ans and b[i + 1];
	}
	cout << ans;
	return 0;
}
