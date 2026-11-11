#include <bits/stdc++.h>
using namespace std;
int x,r;
string wx,wr;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>wr>>x>>wx;
	if(r == x ) {
		cout<<1;
	}else{
		cout<<0;
	}
	if(r == x  && wx[0] == wr[0]&&wx[1] == wr[1]) {
		cout<<1;
	}else{
		cout<<0;
	}
	if(r == x  && wx[0] == wr[0]&&wx[1] == wr[1]&&(wx[2]<=67&&wx[2]>=65&&wr[2]<=67&&wr[2]>=65)) {
		cout<<1;
	}else if(r == x  && wx[0] == wr[0]&&wx[1] == wr[1]&&(wx[2]<=69&&wx[2]>=68&&wr[2]<=69&&wr[2]>=68)){
		cout<<1;
	}else{
		cout<<0;
	}
	if(r == x  && wx[0] == wr[0]&&wx[1] == wr[1]&&(wx[2]<=67&&wx[2]>=65&&wr[2]<=67&&wr[2]>=65)&&(wr[2]-wx[2] == 1||wx[2]-wr[2] == 1)) {
		cout<<1;
	}else if(r == x  && wx[0] == wr[0]&&wx[1] == wr[1]&&(wx[2]<=69&&wx[2]>=68&&wr[2]<=69&&wr[2]>=68)&&(wr[2]-wx[2] == 1||wx[2]-wr[2] == 1)){
		cout<<1;
	}else{
		cout<<0;
	}

	
	return 0;
}
