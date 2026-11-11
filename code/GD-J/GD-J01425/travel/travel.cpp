#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	string a,b[5],c,d[5];
	cin>>a;
	for(int i=1;i<=3;i++){
		cin>>b[i];
	}
	cin>>c;
	for(int i=1;i<=3;i++){
		cin>>d[i];
	}
	if(a==c){
		cout<<'1';
		if(b[1]==d[1]&&b[2]==d[2]){
			cout<<'1';
			if((b[3]>'C'&&d[3]>='D')||(d[3]<'D'&&b[3]<='C')){
				cout<<'1';
				if(b[3]-d[3]==1||d[3]-b[3]==1){
					cout<<'1';
				}
				else{
					cout<<'0';
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
