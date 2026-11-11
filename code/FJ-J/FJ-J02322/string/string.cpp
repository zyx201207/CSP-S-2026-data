#include <iostream>
#include <string.h>
#include <string>
#include <cstdio>
using namespace std;
string s;
int n;
long long cd,bs,a;
char c;
bool hw(void){
	for(int i = 0;i < int(float(cd) / 2 + 0.5);i ++){
		if(s[i] != s[cd - i - 1])
			return false;
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0;i < n;i ++){
		cin >> a >> c;
		cd += a;
		for(int j = 0;j < a;j ++){
			s += c;
		}
	}
	if(!hw()){
		for(long long i = 0;i < int(cd / 2.0 + 0.5);i ++){
			if(s[i] != s[cd - i - 1])
				bs ++;
		}
	}
	cout << bs;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
