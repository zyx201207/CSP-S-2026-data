//GZ-J00413ºØÖªÓîº­
#include<bits/stdc++.h> 
using namespace std;
struct P{
	long long a;
	char c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	P t[20005];
	for(int i = 0;i < n;i++){
		cin >> t[i].a >> t[i].c;
	}
	bool b;
	int s;
	if (n%2 == 0){
		for(int i = 0;i <= n/2;i++){
			if(t[i].c == t[n-i].c&&t[i].a == t[n - i].a){
				b = true;
			}
			else{
				if(t[i].c == t[n-i].c){
					s+= abs(t[i].a - t[n-i].a);
				}
				if(t[i].a == t[n - i].a){
					s += min(t[i].c,t[n-i].c);
				}
			}
		}
	}else{
		for(int i = 0;i <= n/2 + 1;i++){
			if(t[i].c == t[n-i].c&&t[i].a == t[n - i].a){
				b = true;
			}
			else{
				if(t[i].c == t[n-i].c){
					s+= abs(t[i].a - t[n-i].a);
				}
				if(t[i].a == t[n - i].a){
					s += min(t[i].c,t[n-i].c);
				}
			}
		}
	}
	cout << s;
	return 0;
}
