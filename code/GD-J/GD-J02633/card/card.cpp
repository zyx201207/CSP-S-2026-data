#include <iostream>
using namespace std;
int n , m , a , b[300300] ;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m ;
	for(int i=1;i<=n;i++){
		cin >> a ;
		b[a]=i;
	}
	for(int i=1;i<=m;i++){
		cout << b[i] << " " ;
	}
	return 0 ;
}
