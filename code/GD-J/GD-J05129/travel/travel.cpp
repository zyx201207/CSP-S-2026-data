#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int l=1e5+5;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<"1";
		string r,x;
		r+=c2[0]+c2[1];
		x+=s2[0]+s2[1];
		if(r==x){
			cout<<"1";
			if(c2[2]>='A'&&c2[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
				cout<<"1";
				if(c2[2]-1==s2[2]||c2[2]+1==s2[2]){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else if(c2[2]=='D'&&s2[2]=='F'||s2[2]=='D'&&c2[2]=='F'){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
