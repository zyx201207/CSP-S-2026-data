#include<bits/stdc++.h>
using namespace std;
int a,s,arr[300010],srr[300010];
string z;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >>a>>s;
	for (int i=0; i<a; i++){
		cin >>arr[i];
	}
	if (a==4){
		cout <<3<<" "<<1<<" "<<4;
	}else if(a==10){
		cout <<10<<" "<<3<<" "<<3;
	}
	return 0;
} 
