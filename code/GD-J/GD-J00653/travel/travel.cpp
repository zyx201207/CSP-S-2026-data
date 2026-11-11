#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
map<char,int> m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	m['A']=1;
	m['B']=1;
	m['C']=1;
	m['D']=2;
	m['F']=2;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<"1";
		if(b[0]==d[0] && b[1]==d[1]){
			cout<<"1";
			if(m[b[2]]==m[d[2]]){
				cout<<"1";
				if(m[b[2]]==2 || (b[2]=='B' || d[2]=='B')){
					cout<<"1";
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	
	return 0;
}
