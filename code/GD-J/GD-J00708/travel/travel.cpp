#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
long long a[10],b[10];
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>a1>>a2>>b1>>b2;
    a[0]=(a1[0]-'0')*10+(a1[1]-'0');
    a[1]=(a2[0]-'0')*10+(a2[1]-'0');
    a[2]=a2[2];
    b[0]=(b1[0]-'0')*10+(b1[1]-'0');
    b[1]=(b2[0]-'0')*10+(b2[1]-'0');
    b[2]=b2[2];
    if(a[0]==b[0]){
    	s+='1';
	}else{
		s+='0';
	}
	if(s[0]=='1'){
		if(a[1]==b[1]){
		    s+='1';
	    }else{
		    s+='0';
	    }
	}else{
		s+='0';
	}
	if(s[1]=='1'){
		if(a[2]=='A'||a[2]=='B'||a[2]=='C'){
		    if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
			    s+='1';
		    }else{
			    s+='0';
		    }
	    }else{
		    if((a[2]=='E'&&b[2]=='F')||(a[2]=='F'&&b[2]=='E')){
		    	s+='1';
		    }else{
			    s+='0';
		    }
	    }
	}else{
		s+='0';
	}
	if((a[2]-1==b[2]&&s[2]=='1')||(a[2]+1==b[2]&&s[2]=='1')){
		s+='1';
	}else{
		s+='0';
	}
	cout<<s;
	return 0;
}
