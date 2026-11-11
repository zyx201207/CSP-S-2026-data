#include <bits/stdc++.h>
using namespace std;
int n,m,a[20007];

bool cmp(int x, int y){
	return x<y; 
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+m,cmp);
	int ans=a[n-1];
	for(int i=n-1;i>n-1-m;i--){
		ans&=a[i];
	}
	cout << ans << endl;
	return 0;
}
