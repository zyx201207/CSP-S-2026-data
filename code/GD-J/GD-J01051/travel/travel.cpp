#include<bits/stdc++.h>
using namespace std;
struct a{
	string lie;
	int hang;
}s[1000001];
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdin");
	for(int i = 1;i<=2;i++){
		cin >> s[i].hang >> s[i].lie;
	}
	if (s[1].hang == s[3].hang){
		cout << "1";
		if(s[1].lie/100 == s[2].lie/100){
			cout << "1";
			if((s[1].lie%100<='C'&&s[2].lie%100<='C')||(s[1].lie%100>='D'&&s[2].lie%100>='D')){
				cout << "1";
				if((s[1].lie%100-1==s[2].lie&&s[1].lie%100!='D')||((s[2].lie%100-1==s[1].lie&&s[2].lie%100!='D')){
					cout << "1";
				}else{
					cout << 0;
				}
			}else{
				cout << 0;
			}
		}else{
			cout << 0;
		}
	}else{
		cout << 0;
	}
	return 0;
} 

































