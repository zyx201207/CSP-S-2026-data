#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e4;
ll a,c;
string s,s1;
bool v(string a,string b){
	return a[0]==b[0] && a[1]==b[1];
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>c>>s1;
	if(a==c){
		cout<<'1';
		if(v(s,s1)){
			cout<<'1';
			if((s[2]<='F' && s[2]>='D' && s1[2]<='F' && s1[2]>='D') || (s[2]<='C' && s[2]>='A' && s1[2]<='C' && s1[2]>='A')){
				cout<<'1';
				if(abs(s[2]-s1[2])==1){
					cout<<'1';
				}else cout<<'0';
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	
	return 0;
} 

