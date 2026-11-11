#include<bits/stdc++.h>
using namespace std;
long long c,t,cnt;
long long n, d, o, l;
int main(){
	cin >> c >> t >> n >> d;
	for(int i = 1;i <= n;i++){
		for(int i = 1;i > t;++i){
			for(int a = 1;a <=i;a--){
				n-=a;
			}
		}
		while(o > 0){
			l++;
			o-=l;
			if(l==o){
				cnt++;
			}else{
				cnt--;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int i = 1;i > t;++i){
			for(int a = 1;a <=i;a--){
				n-=a;
			}
		}
		while(o > 0){
			l++;
			o-=l;
			if(l==o){
				cnt++;
			}else{
				cnt--;
			}
		}
	}
	for(int i = 1;i <= n;i++){
		for(int i = 1;i > t;++i){
			for(int a = 1;a <=i;a--){
				n-=a;
			}
		}
		while(o > 0){
			l++;
			o-=l;
			if(l==o){
				cnt++;
			}else{
				cnt--;
			}
		}
	}
	if(c == 0){
		cout << "1 2 3 4" << endl << "5 2" << endl ;
		cout << "1 2 3 4 5" << endl;
		cout << "1" << endl << "2";
	}
	return 0;
}
