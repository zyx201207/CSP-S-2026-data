#include<bits/stdc++.h>
using namespace std;
int n,c;
int a[1000000];
char b[1000000];
int main(){
	freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	cin >> n;
	for(int i =0;i<n;i++)
	cin >> a[i] >> b[i];
	if(n == 1){
		cout <<"0";
		return 0;
	}else if(n == 2){
		if(b[0] != b[1]){
			cout << min(a[0],a[1]);
			return 0;
		}else {
			cout << "0";
			return 0;
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < n;j++){
			if('b[i]' != 'b[j]'){
				break;
				c == 1;
			}
		}
	}if( c == 0){
		cout << "0";
		return 0;
	}
}
