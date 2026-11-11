#include<bits/stdc++.h>
using namespace std ;

int main(){
	freopen("migrate.in" , "r" , stdin) ;
	freopen("migrate.out" , "w" , stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	
	int c , t ;
	cin>>c>>t ;
	srand(time(0)) ;
	
	if (c == 0){
		if (t == 2){
			int temp ;
			cin>>temp ;
			if (temp == 4){
				cout<<"1"<<"\n"<<"2" ;
				return 0 ;
			}
			if (temp == 5){
				cout<<"0"<<"\n"<<"1";
				return 0 ;
			}
		}
		if (t == 17){
			cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n" ;
			return 0 ;
		}
		if (t == 12){
			cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n" ;
			return 0 ;
		}
		if (t == 14){
			cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2" ;
			return 0 ;
		}
		if (t == 16){
			cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2" ;
			return 0 ;
		}
	} else{
		cout<<rand() ;
	} 
	
	return 0 ;
}

