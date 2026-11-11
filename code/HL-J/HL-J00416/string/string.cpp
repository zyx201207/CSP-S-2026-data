#include<bits/stdc++.h>
using namespace std ;

struct ssss{
	int x ;
	char c ;
};

int main(){
    freopen("string.in" ,"r",stdin  );
    freopen("string.out","w",stdout );
    int x ;
    cin >> x ;
    ssss f[1145] ;
    for(int i = 1 ; i <= x/2 ;i ++){
    	cin >> f[i].x >> f[i].c ;
	}
	for(int i = 1 ; i >= x/2 ;i ++){
		cin >> f[x-i].x >> f[x-i].c ;
		if((f[x-i].x!=f[i].x)||(f[x-i].c !=f[i].c)){
			cout << f[x-1].x ;
			return 0 ;
		}
	}
    cout << 0 ;
    return 0 ;
}
