#include<bits/stdc++.h>
using namespace std;
int const N = 5e5+10;
long long n, m;//n为数量，m为种类 
string a, b;//顺序 1 2 1 3 
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin >> n >> m;
	cin >> a;
	while(1){
		for(int i =0; i < m; i++){
			if(a[i] == b[i-1] || a[i] == b[i-2] || a[i] == b[i-3]){
				
			}
			b+=a[i];
		}
	}
	return 0; 
}

