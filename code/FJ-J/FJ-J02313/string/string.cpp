#include<bits/stdc++.h>
using namespace std;
const int N = 10000000;
long long a[N],c[N];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int i = 1; i <= n; i++){
			cin >> a[i] >> c[i];
			    if(c[i] == c[i]){
			    cout << 0;
		    } 
		}
	} 
	return 0;
}

