#include<bits/stdc++.h>
using namespace std;
long long a_box,a_row,a_seat;
long long b_box,b_row,b_seat;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a_box>>a>>b_box>>b;
	a_row=(a[0]-'0')*10+(a[1]-'0');
	b_row=(b[0]-'0')*10+(b[1]-'0');
	a_seat=a[2]-'A'+1;
	b_seat=b[2]-'A'+1;
	if(a_seat>b_seat) swap(a_seat,b_seat);
//	cout<<a_box<<' '<<b_box<<"\n";
//	cout<<a_row<<' '<<b_row<<"\n";
//	cout<<a_seat<<' '<<b_seat<<"\n";
	if(a_box==b_box) {
		cout<<1;
		if(a_row==b_row) {
			cout<<1;
			if((a_seat<=3&&b_seat<=3)||(a_seat>3&&b_seat>3)) {
				cout<<1;
				if(abs(a_seat-b_seat)==1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
