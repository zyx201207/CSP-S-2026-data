#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a,b,s,t;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>t;
	if(a==b){
		cout<<1;
		string s1=s.substr(0,2);
		string t1=t.substr(0,2);
		if(t1==s1){
			cout<<1;
			if((s[2]<='C')==(t[2]<='C')){
				cout<<1;
				if(abs(s[2]-t[2])==1){
					cout<<1;
				}else{
					cout<<"0";
				}
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

