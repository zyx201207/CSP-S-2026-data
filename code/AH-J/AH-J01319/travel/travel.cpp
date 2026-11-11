#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
string s;
int ch(string x){
	return (x[0]-'0')*10+(x[1]-'0');
}
bool check(string a,string b){
	char c=a[2],d=b[2];
	if((c>='A'&&c<='C'&&d>='A'&&d<='C')||(c>='D'&&c<='F'&&c!='E'&&d>='D'&&d<='F'&&d!='E')){
		return 1;
	}
	return 0;
}
bool c2(string a,string b){
	char c=a[2],d=b[2];
	if((c=='A'&&d=='B')||(c=='B'&&d=='C')||(c=='B'&&d=='A')||(c=='C'&&d=='B')||(c=='D'&&d=='F')||(c=='F'&&d=='D')){
		return 1;
	}
	return 0;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b>>c>>d;
    if(a==c){
        s+="1";
    }else{
		s+="0";
	}
	if(a==c&&ch(b)==ch(d)){
		s+="1";
	}else{
		s+="0";
	}
	if(a==c&&ch(b)==ch(d)&&check(b,d)==1){
		s+="1";
	}else{
		s+="0";
	}
	if(s=="111"&&c2(b,d)==1){
		s+="1";
	}else{
		s+="0";
	}
	cout<<s;
    return 0;
}
