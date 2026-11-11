#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;

//#define int long long
string s1_1,s1_2,s2_1,s2_2;

//unsigned
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	
	cin>>s1_1>>s1_2>>s2_1>>s2_2;
	if(s1_1==s2_1){
		cout<<1;
		if(s1_2.substr(0,2)==s2_2.substr(0,2)){
			cout<<1;
			char x=s1_2[2],y=s2_2[2];
			
			if(x>='A'&&x<='C'&&y>='A'&&y<='C') {
				cout<<1;
				if(abs(x-y)<=1) cout<<1;
				else cout<<0;
			}else if(x>='D'&&x<='E'&&y>='D'&&y<='E') cout<<11;
			else cout<<"00";
		}else cout<<"000";
		
	}else cout<<"0000";
	
	
	
	return 0;
}

