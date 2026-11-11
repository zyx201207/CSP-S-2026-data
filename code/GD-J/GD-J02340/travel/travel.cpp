#include<bits/stdc++.h>
using namespace std;
struct s{
	string a,b;
}a,b;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>a.a>>a.b>>b.a>>b.b;
	if(a.a==b.a){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(a.b[0]=b.b[0]&&a.b[1]==b.b[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	char chx=a.b[2],chy=b.b[2];
	if(chx=='A'||chx=='B'||chx=='C'){
		if(chy=='A'||chy=='B'||chy=='C'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		if(chy=='F'||chy=='D'){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
	}
	if(chx=='A'&&chy=='B')cout<<1;
	else if(chx=='B'&&(chy=='A'||chy=='C'))cout<<1;
	else if(chx=='C'&&chy=='B')cout<<1;
	else if(chx=='D'&&chy=='F')cout<<1;
	else if(chx=='F'&&chy=='D')cout<<1;
	else cout<<0;
	return 0;
}
