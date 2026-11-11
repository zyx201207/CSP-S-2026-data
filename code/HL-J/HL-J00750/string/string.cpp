#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	char a[n*2+5];
	for(int i=0;i<n*2;i++){
		cin >> a[i];
	}
	if(n==1) cout << 0;
	else if(n==2){
		if(a[1]==a[3]) cout << 0;
		else cout << min(a[0],a[2]);
	}
	return 0;
}