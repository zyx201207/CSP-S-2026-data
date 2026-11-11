#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s_1,s_2;
ll c_1,c_2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c_1>>s_1>>c_2>>s_2;
	if(c_1==c_2){
		cout<<1;
		if(s_1.substr(0,2)==s_2.substr(0,2)){
			cout<<1;
			int z_1=s_1[2]-'A',z_2=s_2[2]-'A';
			if((z_1<3&&z_2<3)||(z_1>2&&z_2>2)){
				cout<<1;
				if(abs(z_1-z_2)==1)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
}
