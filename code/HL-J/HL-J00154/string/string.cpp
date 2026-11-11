#include<bits/stdc++.h>
using namespace std;
int n,x,x1;
char y;
char b[10005];
int main(){
	cin >> n;
	for(int i = 0;i < n;i++){
	    cin >> x;
	    cin >> y;
	    b[i] = y;
	    for(int j = 0;j < x;j++){
	    	b[i+1] = y;
		}
	    x1 += x;
	}
	int num = 0;
	for(int i = 1; i <= x1;i++){
		if(b[i-1] == b[x1 - i]){
			num += 0;
		}else{
			num += 1;
		}
	}
	cout << num;
	return 0;
}

