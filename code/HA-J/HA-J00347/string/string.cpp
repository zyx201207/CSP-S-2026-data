#include<bits/stdc++.h>
using namespace std;
long long n, sum, l, r, m;
string a;
char f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> m;
	for (int j = 1;j <= m ; j++){
		cin >> n >> f;
		r += n;
		for(int i = l;i < r ; i++){
			a[i]=f;
			l++;
		}
	}
	for (int i = 0 ; i <= r/2 ; i++ ){
		if(a[i]!=a[r-1]){
			sum++;
		}
	}
	cout << sum;
	return 0;
}
