#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1])cout<<1;
	else{
		cout<<"000";
		return 0;
	} 
	if(b[b.size()-1]>='A'&&b[b.size()-1]<='C'){
		if(d[d.size()-1]>='A'&&d[d.size()-1]<='C'){
			cout<<1;
			if(abs((b[b.size()-1]-'0')-(d[d.size()-1]-'0'))==1)cout<<1;
			else cout<<0;
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		if(d[d.size()-1]=='D'||d[d.size()-1]=='F'){
			cout<<1;
			if(abs((b[b.size()-1]-'0')-(d[d.size()-1]-'0'))==2)cout<<1;
			else cout<<0;
		}else{
			cout<<"00";
			return 0;
		} 
	}
	return 0;
}
