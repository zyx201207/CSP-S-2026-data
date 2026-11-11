#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a = INT_MIN , b[200020] , n , m;
	cin >> n >> m;
	if(m == 1){
		for(int i = 1;i <= n;i++){
			cin >> b[i];
			if(b[i] >= a)a = b[i];
		}
	}
	cout << a;
	return 0;
}
