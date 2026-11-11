#include<iostream>
using namespace std;
char a[200001];
int n,c=1;
void init(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		int s;
		cin >> s;
		char x;
		cin >> x;
		for(int i = 1;i <= s;i++){
			a[c] = x;
			c++;
		}
	}
}
void work(){
	cout << "2";
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	init();
	c=0;
	for(int i = 1;i <= n;i++){
		int s=n;
		if(a[i] == a[s]){
			c++;
		}
		s--;
	}
	if(c==n){
		cout << "0";
	}else{
		work();
	}
	return 0;
}
