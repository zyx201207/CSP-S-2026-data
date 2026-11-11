//GZ-J00382;山水中学;史睿琦//
#include <iostream>;
using namespace std;
int main(){
	int n,c,a,m,d,f,g;
	string s;
	cin >> n;
	m = 0;
	d = 0;
	f = a -1;
	while(m < n){
		cin >> a,c;
		m++;
	}
	s = c * a;
	while(f != g){
        if(s[f] == s[g]){
            cout << 0;
            f--;
            g++;
        }else{
            d++;
        }
	}
	cout << d;
	return 0;
}
