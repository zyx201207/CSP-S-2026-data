#include<bits/stdc++.h>
using namespace std;
struct ly{
	string cx;
	string zy;
};
int a,b;
signed mian()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>aa.cx>>aa.zy>>ba.cx>>ba.zy;
	for(int i=0;i<aa.cx.size();i++){
		ab*=10;
		ab+=aa.cx[i]-'0';
	}
	for(int i=0;i<ba.cx.size();i++){
		bb*=10;
		bb+=aa.cx[i]-'0';
	}
	cout<<ab<<" "<<bb;
	return 0;
}
