#include <bits/stdc++.h>
using namespace std;
string a;
long long cnt,d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		char z;
		long long b;
		cin >> b >> z;
		d += b;
		for(int j=1;j<=b;j++){
			a += z;
		}
	}
	for(int c=0;c<d;c++){
		if(a[0]-a[c]>1||a[c]-a[0]>1){
			cnt++;
		}
	}
	for(int h=0;h<d-1;h++){
		if(a[0]==a[h+1]){
			cnt++;
		}
		else{
			break;
		}
	}
	if(a[0]==a[1]){
		cnt++;
	}
	
	cout << cnt;
	return 0;
}
