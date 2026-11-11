#include <bits/stdc++.h>
#define int long long 
using namespace std;
int a,c,b1,d1;
string b,d;
char cnt1,cnt2;
signed main(){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if (a==c)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	b1=(b[0]-'0')*10+(b[1]-'0');
	d1=(d[0]-'0')*10+(d[1]-'0');
	if (b1==d1)cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	cnt1=b[2];
	cnt2=d[2];
	if (cnt1=='A'||cnt1=='B'||cnt1=='C'){
		if (cnt2=='A'||cnt2=='B'||cnt2=='C')cout<<"1";
		else{
			cout<<"00";
			return 0;
		}
	}
	else {
		if (cnt2=='D'||cnt2=='F')cout<<"1";
		else {
			cout<<"00";
			return 0;
		}
	}
	if (cnt1=='A'){
		if (cnt2=='B')cout<<"1";
		else{
			cout<<"0";
			return 0;
		} 
	}
	if (cnt1=='B'){
		if (cnt2=='A'||cnt2=='C')cout<<"1";
		else{
			cout<<"0";
			return 0;
		} 
	}
	if (cnt1=='C'){
		if (cnt2=='B')cout<<"1";
		else{
			cout<<"0";
			return 0;
		} 
	}
	if (cnt1=='D'){
		if (cnt2=='F')cout<<"1";
		else{
			cout<<"0";
			return 0;
		} 
	}
	if (cnt1=='F'){
		if (cnt2=='D')cout<<"1";
		else{
			cout<<"0";
			return 0;
		} 
	}
	return 0;
}
