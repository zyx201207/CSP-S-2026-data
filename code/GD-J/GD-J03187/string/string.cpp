#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int numa,numb,numc,all = 0;
	char a,b,c;
	vector<char> cnta,cntb,cntc;
	cin >> n;
	if(n == 1) {
		cin >> numa >> a;
		for(int i = 0;i <= numa;i++){
			cnta.push_back('a');
		}
	}
	if(n == 2){
		cin >> numa >> a;
		cin >> numb >> b;
		for(int i = 0;i <= numa;i++){
			cnta.push_back('a');
		}
		for(int j = 0;j <= numb;j++){
			cntb.push_back('b');
		}
	}
	if(n == 3){
		cin >> numa >> a;
		cin >> numb >> b;
		cin >> numc >> c;
		for(int i = 0;i <= numa;i++){
			cnta.push_back('a');
		}
		for(int j = 0;j <= numb;j++){
			cntb.push_back('b');		
		}
		for(int k = 0;k <= numc;k++){
			cntc.push_back('c');
		}
	
}
	
	return 0;
}
