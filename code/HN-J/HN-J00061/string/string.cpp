#include <bits/stdc++.h>
using namespace std;

int a,b,c,d;
string x,y,z;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> a;
	for(int i = 1;i <= a;i++){
		cin >> b >> x;
		c += b;
		for(int i = 1;i <= b;i++){
			s += x;
		}
	}
	if(c%2==1){
		for(int i=0;i<=c/2;i++){
			y+=s[i];
		}
		for(int i=c-1;i>=c/2;i--){
			z+=s[i];
		}
		for(int i = 0;i <= c/2;i++){
			if(y[i] != z[i]) d++;
		}
	}
	if(c%2==0){
		for(int i=0;i<=c/2-1;i++){
			y+=s[i];
		}
		for(int i=c-1;i>=c/2;i--){
			z+=s[i];
		}
		for(int i = 0;i <= c/2;i++){
			if(y[i] != z[i]) d++;
		}
	}
	//cout << y << z;
	//cout << s;
	cout << d;
}

