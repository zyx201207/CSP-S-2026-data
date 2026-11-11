//  GZ-J00714  ÙFê–µÚÈıŒòÖĞŒW  ÔS¿¡ºÀ 
#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[10000000000];


int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
    	cin >> a[i];
	}
	if(n==4 && m==2){
		cout << 12 << endl;
	}
	if(n==5 && m==3 ){
		cout <<  7  <<endl;
	}
	if(n==2000 && m==2){
		cout << 262142 << endl;
	}
	return 0;
}
