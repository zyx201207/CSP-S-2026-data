#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,e,f;
	char c,d;
	cin >> a >> e >> c >> b >> f >> d;
	int t=0;
	if(a == b){
		t=1;
		cout << 1 ;
	}else{
		cout << 0 ;
	}
	if(t == 1 && e == f){
		cout << 1;
	}else{
		t = 0;
		cout << 0;
	}
	if(t == 1 && ((c <= 'C' && d <= 'C') || (c > 'C' && d > 'C'))){
		cout << 1;
	}else{
		t =0;
		cout << 0;
	}
	if(t == 1 && ((char(c+1) == d) || (char(c-1) == d))){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
}
