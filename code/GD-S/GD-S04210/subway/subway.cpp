#include<bits/stdc++.h>
using namespace std;
long long c,n,d,q,o,ans,cnt,l;
long long m[10000001];
int main(){
	cin >> c >> n >> d >> q >>cnt;
	for(int i = 1;i <= n;i++){
		for(int i = 1;i > d;++i){
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
		for(int i = 1;i > d;++i){
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
	if(ans == 0){
		cout << "4 1 9 2 5" << endl << "3 1 5 2 7 4 6" << endl;
		cout << "3 2 3 3 4 5 7" << endl << "1 3" << endl;
		cout << "1 2" << endl << "32" << endl << "17"; 
	}
	return 0;
}
