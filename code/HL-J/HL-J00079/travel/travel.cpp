#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen ( "travel.in","r",stdin ) ;
	freopen ( "travel.out","w",stdout );
	int n , m , p , q;
	char a , b;
	cin >> n >> m >> a >> p >> q >> b;
	if( n == p ){
		cout << "1";
	} else{
		cout << "0000";
		return 0;
	}

//	cout << n << " " << m << " " << a << " " << p << " " << q << " " << b;
 	if(m == q){
		cout << "1";
		if (a == 'A' && b == 'B' ||a == 'A' && b == 'C' ||
			a == 'B' && b == 'A' ||a == 'C' && b == 'A' ||
			a == 'C' && b == 'B' ||
			a == 'B' && b == 'C' ||
			a == 'D' && b == 'F' ||
			a == 'F' && b == 'D' ){
			cout <<"1";
			if(a == 'A' && b == 'B' || 
				a == 'B' && b == 'A' ||
				a == 'C' && b == 'B' ||
				a == 'B' && b == 'C' ||
				a == 'D' && b == 'F' ||
				a == 'F' && b == 'D'){
					cout << "1";
			}else{
					cout << "0";
					return 0;
			}
		}else{
			cout << "00";
			return 0;
		}
		
	}else{
		cout << "000";
	}
		return 0;
}
	/*
	ab
	ac
	ad
	af
	bc
	bd
	bf
	cd
	cf
	df
	 */
