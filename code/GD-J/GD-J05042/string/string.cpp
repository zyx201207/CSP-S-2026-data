#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r","stdin");
	freopen("string.out","W","stdout");
	int n;
	cin >> n;

	int m;
char l;
char a[100000] ,b[100000],c[100000];
	int cnt = 0;
	for(int i = 0; i < n;i++){
		cin >> m >> l;
	
		for(int j = 0; j < m;j++){
			a[cnt] = l;
			cnt++;
		}
	}
	
if(cnt %2 == 0){
	for(int i = 0; i < cnt/2;i++){
		b[i] = a[i];
		c[i] = a[i+cnt/2];
	}
}else{
	for(int i = 0; i < cnt/2;i++){
		b[i] = a[i];
		c[i] = a[i+cnt/2+1];
	}
}
	     int sum = 0;
	     for(int i = 0; i < cnt /2;i++ ){
	     	if(b[i] != c[i]) {
	     		sum++;
			 }
		 }
		 cout << sum;
	return 0;
}
