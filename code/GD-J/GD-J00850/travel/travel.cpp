#include<bits/stdc++.h>
using namespace std;
#define int long long
int c1,c2,a,b,x,y;
string s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=(s1[0]-48)*10+(s1[1]-48);
	b=(s2[0]-48)*10+(s2[1]-48);
	x=s1[2]*10/10-64;
	y=s2[2]*10/10-64;
	if(c1!=c2){
		cout<<0<<0<<0<<0;
		return 0;
	}
	else cout<<1;
	if(a!=b){
		cout<<0<<0<<0;
		return 0;
	}
	else cout<<1;
	if((x>3 && y<=3) || (x<=3 && y>3)){
		cout<<0<<0;
		return 0;
	}
	else cout<<1;
	if(x-y==1 || x-y==-1) cout<<1;
	else cout<<0;
	return 0;
}
