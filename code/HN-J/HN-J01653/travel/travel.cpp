#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		ll num1=(s1[0]-'0')*10+s1[1]-'0';
		ll num2=(s2[0]-'0')*10+s2[1]-'0';
		if(num1==num2){
			cout<<1;
			ll x=s1[2]-'A';
			ll y=s2[2]-'A';
			if((x<3&&y<3)||(x>=3&&y>=3)){
				cout<<1;
				if(x>y) swap(x,y);
				if(x==y-1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}

