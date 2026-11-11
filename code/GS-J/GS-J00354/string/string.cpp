#include<bits/stdc++.h>
using namespace std;
int aa[100005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,b=0;
	string a;
	cin >> n;
	for(int i= 0;i<n;i++){
		cin >> aa[i] >> a[i];
	}
	for(int i= 0;i < n;i++){
		b+=aa[i];
	}
	for(int i= 0;i<b;i++){
		cout << a[0];
	}
	return 0;
}
