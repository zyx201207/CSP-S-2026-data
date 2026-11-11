#include <iostream>
using namespace std;
int n , sum , a ;
char c ;
string s ;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n ;
	for(int i=1;i<=n;i++){
		cin >> a >> c ;
		for (int j =1;j<=a;j++){
			s+=c;
		}
	}
	int m = s.size() ;
	for(int i=1;i<=m/2;i++){
		if(s[i]!=s[m+1-i]){
			sum++;
		}
	}
	cout << sum << endl ;
	return 0 ;
}
