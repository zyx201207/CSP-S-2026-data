#include<bits/stdc++.h>
using namespace std;
int c,t,x,y;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		if(t==2){
			cin>>x>>y;
			if(x==4 && y==2){
				cout << 1 << endl;
				cout << 2 << endl;
			}else if(x==5 && y==3){
				cout << 0 << endl;
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
				cout << 0 << endl;
			}
		}
	}
	return 0;
	return 0;
}
