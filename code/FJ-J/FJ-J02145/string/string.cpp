#include <bits/stdc++.h>
using namespace std;
int n;
string a[200005],b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i];
	}
	if(n==1){
		cout << "0";
		return 0;
	}else if(n==2){
		if(b[1]==b[2]){
			cout << "0";
			return 0;
		}else if(a[1]<=a[2]){
			cout << a[1];
			return 0;
		}else{
			cout << a[2];
			return 0;
		}
	}
	cout << "0";
	return 0;
}