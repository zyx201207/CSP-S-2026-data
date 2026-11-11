#include<bits/stdc++.h>
using namespace std;
int a,b,flag;
string aa,bb;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>b>>bb;
	if(a==b) {
		cout<<1;
		flag=1;
	}
	else cout<<0;
	if(flag==0) {
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	string a1,b1,a2,b2;
	a1+=aa[0];
	a1+=aa[1];
	b1+=bb[0];
	b1+=bb[1];
	a2=aa[2];
	b2=bb[2];
	//cout<<a1<<" "<<b1<<" "<<a2<<" "<<b2;
	if(a1==b1) cout<<1;
	else cout<<0;
	if(a1==b1) {
		if(a2=="A"||a2=="B"||a2=="C") {
			if(b2=="A"||b2=="B"||b2=="C") {
				cout<<1;
			}
			else cout<<0;
		}
		if(a2=="D"||a2=="F") {
			if(b2=="D"||b2=="F") {
				cout<<1;
			}
			else cout<<0;
		}
	}
	else cout<<0;
	if((a1==b1)&&((a2=="A"&&b2=="B")||(a2=="B"&&b2=="A")||(a2=="C"&&b2=="B")||(a2=="B"&&b2=="C")||(a2=="D"&&b2=="F")||(a2=="F"&&b2=="D"))) cout<<1;
	else cout<<0;
	return 0;
} 

