#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s , b;
	double n , a , m = 0;
	cin >> n;
	for(double i = 1;i <= n;i ++){
		cin >> a >> b;
		for(double j = 1;j <= a;j ++){
			s += b;
		}
	}for(double i = 0;i < floor(s.size()/2);i++){
		if(s[i] != s[s.size()-1-i]){
			m ++;
		}
	}
	cout << m;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
