#include<bits/stdc++.h>
using namespace std;
int a,b;
char c,d,e,f,g,h,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> c >> d >> e >> b >> f >> g >> h;
	if(a==b){
		cout << 1;
	}
	else{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	if(c==f&&d==g){
		cout << 1;
	}
	else{
		cout << 0 << 0 << 0;
		return 0;
	}
	if(e=='A'||e=='B'||e=='C'){
		if(h=='D'||h=='F'){
			cout << 0;
			ans++;
		}
	}
	else if(h=='A'||h=='B'||h=='C'){
		if(e=='D'||e=='F'){
			cout << 0;
			ans++;
		}
	}
	if(ans==0){
		cout << 1;
	}
	if(e+1==h&&e!='C'){
		cout << 1;
	}
	else if(e+2==h&&e=='D'){
		cout << 1;
	}
	else if(h+1==e&&h!='C'){
		cout << 1;
	}
	else if(h+2==e&&h=='D'){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}
