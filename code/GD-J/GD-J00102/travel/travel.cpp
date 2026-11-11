#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
string ap,bp;
char az,bz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	std::sycn_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	ap = s1[0] + s1[1];
	bp = s2[0] + s2[1];
	az = s1[2];
	bz = s2[2];
	if(c1 == c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1 == c2 && ap == bp){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1 == c2 && (ap == bp) && ((az <= 'C' && bz <= 'C') || (az >= 'D' && bz >= 'D'))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1 == c2 && (ap == bp) && abs((az - 'A') - (bz - 'A')) == 1 && !((az == 'C' && bz == 'D') || (az == 'D' && bz == 'C'))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
