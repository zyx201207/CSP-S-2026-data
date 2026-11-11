#include <bits/stdc++.h>

using namespace std;
int a,b;
const int N=2e6+10;
long long n[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out ","w",stdout);
	cin >> a >> b;
	for(int i=1;i<=a;i++){
		cin >> n[i];
	}
	if(b==1){
		sort(n+1,n+a+1);
		cout << n[a];
	}else{
		sort(n+1,n+a+1);
		if(b==a){
			cout << n[1];
		}else if(b==2){
			sort(n+1,n+a+1);
			cout << n[a-1];
		}else{
			cout <<"0";
		}
	}
	return 0;
}
//Trick||Treat!
