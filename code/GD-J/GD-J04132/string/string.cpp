#include <bits/stdc++.h>
using namespace std;
long long a[110000];
char b[110000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	if(n <= 1){
		cout<<"0";
		return 0;
	}
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	if(n<=2){
		if(n <= 1){
			cout<<"0";
			return 0;
		}
		if(b[1] == b[2]){
			cout<<"0";
			return 0;
		} 
		else if(a[1] > a[2]){
			cout<<a[2];
		}
		else if(a[2] > a[1]){
			cout<<a[1];
		}
	}
	return 0;
}
