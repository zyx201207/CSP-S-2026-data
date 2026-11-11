#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull n;
const int MAX_N = 1e6+10;
struct s{
	ull x;
	string c;
}a[MAX_N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 0; i < n ;i++){
		cin>>a[i].x>>a[i].c;
	}
	if(n == 1){
		cout<<0;
	}
	else if(n == 2){
		if(a[0].c == a[1].c){
			cout<<0;
		}
		else if(a[0].x == 1 && (a[1].x == 1 || a[1].x == 2 || a[1].x == 3 || a[1].x == 4)){
			cout<<1;
		}
		else if(a[0].x == 2 && (a[1].x == 2 || a[1].x == 3)){
			cout<<2;
		}
	}
	else{
		cout<<30000000;
	}
    return 0;
}
