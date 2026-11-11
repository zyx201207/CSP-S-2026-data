#include <bits/stdc++.h>
using namespace std;
string www="0";
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.in","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a;
	char b;
	int n,s=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a >> b;
		for(int j=1;j<=b;j++){
			www=www+b;
		}
	}
	int wang=www.size()-1;
	for(int i=1;i<=wang/2;i++){
		if(www[i]!=www[wang-i+1]){
			s++;
		}
	}
	cout << s;
	
	return 0;
}
