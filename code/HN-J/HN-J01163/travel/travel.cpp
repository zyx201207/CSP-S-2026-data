#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ac,bc,ap,bp;
	char az,bz;
	cin>>ac>>ap>>az>>bc>>bp>>bz;
	
	if((ac==bc))cout<<1;
	else cout<<0;
	if((ac==bc&&ap==bp))cout<<1;
	else cout<<0;
	if(ac==bc&&ap==bp&&((az<='C'&&bz<='C')||(az>='D'&&bz>='D')))cout<<1;
	else cout<<0;
	if((ac==bc&&ap==bp&&((az<='C'&&bz<='C')||(az>='D'&&bz>='D'))&&abs(az-bz)==1))cout<<1;
	else cout<<0;
	return 0;
}
