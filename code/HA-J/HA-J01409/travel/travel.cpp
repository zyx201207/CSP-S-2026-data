#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a;
	getline(cin,a);
	char B='C';
	if(a[0]==a[7] && a[1]==a[8]) {
		cout<<1;
		if(a[3]==a[10] && a[4]==a[11]) {
			cout<<1;
			if((a[5]<=(int)B && a[12]<=(int)B) || (a[5]>(int)B && a[12]>(int)B)) {
				cout<<1;
				if(((int)a[5]-(int) a[12]==1) || ((int)a[5]-(int) a[12]==-1)) cout<<1<<endl;
				else cout<<0<<endl;
			} else cout<<"00";
		} else cout<<"000"<<endl;
	} else cout<<"0000"<<endl;
	return 0;
}