#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string1.in","r",stdin);
	freopen(" string1.ans","w",stdout);
	int n , a , cnt = 0,x = 0;
	char b,c[1001];
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a;
		cnt += a;
	}
	for(int i = 0; i < n; i++){
		cin >> b;
		for(int j = 0; j < cnt ;j++){
			c[j] = b;
		}
	}
	for(int i = 0; i < cnt; i++){
		for(int j = cnt - 1; j >= 0; j--){
			if(c[i] != c[j]){
				c[j] = c[i];
				x++;
			}
		}
	}
	cout << x;
	return 0;	 
}
