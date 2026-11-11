#include<bits/stdc++.h>
using namespace std;
map<char,int>mp;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000\n";
		return 0;
	}
	cout<<1;
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if((b[2]>='A'&&b[2]<='C')&&(d[2]>='A'&&d[2]<='C')){
		cout<<1;
	}
	else if((b[2]>='D'&&b[2]<='E')&&(d[2]>='D'&&d[2]<='E')){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	mp['A']=1;
	mp['B']=2;
	mp['C']=3;
	mp['D']=4;
	mp['E']=5;
	if(abs(mp[b[2]]-mp[d[2]])==1)cout<<1;
	else cout<<0;
	return 0;
} 
