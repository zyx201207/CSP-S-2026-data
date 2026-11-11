#include<bits/stdc++.h>
using namespace std;
string a;
long long q,arr[200010],ans;
char srr[200010];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>q;
	for (int i=0; i<q; i++){
		cin >>arr[i]>>srr[i];
		for (int o=0; o<arr[i]; o++){
			a+=srr[i];
		}
	}
	for (int i=0; i<a.size()/2; i++){
		if (a[i]!=a[a.size()-i-1]){
			ans++;
		}
	}
	cout <<ans;
	return 0;
}
