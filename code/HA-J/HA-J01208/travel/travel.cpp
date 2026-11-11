#include<bits/stdc++.h>
using namespace std;
bool cx,cp,tc,xl;
int main(){	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1[0] == c2[0] && c1[1] == c2[1]){
		cx = 1;
		cout << 1;
	}else{
		cx = 0;
		cout << 0;
	}
	if((s1[0] == s2[0] && s1[1] == s2[1]) && cx == 1){
		cp = 1;
		cout << 1;
	}else{
		cp = 0;
		cout << 0;
	}
	char str = s1[2],stri = s2[2];
	if(cx == 1 && cp == 1 && ((str >= 'A' && str <= 'C' && stri >= 'A' && stri <= 'C') ||(str >= 'D' && str <= 'F' && stri >= 'D' && stri <= 'F'))){
		tc = 1;
		cout << 1;
	}else{
		tc = 0;
		cout << 0;
	} 
	int n = int(str), m = int (stri);
	if(cx == 1 && cp == 1 && tc == 1 && !((n == 67 && m == 68) || (n == 68 && m == 67))){
		if(abs(n - m) == 1){
			xl = 1;
			cout << 1;
		}else{
			xl = 0;
			cout << 0;
		} 
	}else{
		xl = 0;
		cout << 0;
	} 
	
	return 0;
}
