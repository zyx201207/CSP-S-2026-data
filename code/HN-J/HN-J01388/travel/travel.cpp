#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c >> a >> d >> b;
	if(c==d) cout << 1;
	else{
		cout <<"0000";
		return 0;
	}
	if(a[1]==b[1] && a[0]==b[0]){
		cout<<1;
		if((a[2]>='A' && a[2]<='C' && b[2]>='A' && b[2]<='C') || (a[2]>='D' && a[2]<='F' && b[2]>='D' && b[2]<='F')){
			cout<<1;
			if((a[2]+1==b[2] && b[2]!='D') || (b[2]+1==a[2] && a[2]!='D')){
				cout << 1;
				return 0;
			}else{
				cout << 0;
			}
		}else{
			cout<<"00";
		}
	}else{
		cout << "000";
	}
	return 0;
}
