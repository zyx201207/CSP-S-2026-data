#include<iostream>
#include<cstdio>
using namespace std;
string a,b,c,d,s="";
int main(){
	cin>>a>>b>>c>>d;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    if(a[0]==c[0]&&a[1]==c[1]){
         s+='1';
    }else{
        s+='0';
	}
    if(b[0]==d[0]&&b[1]==d[1]){
		s+='1';
	}else{
        s+='0';
	}
    if((s[1]=='1')&&((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'))){
	    s+='1';
    }else{
		s+='0';
    }
    if(s[0]=='1'&&s[1]=='1'&&s[2]=='1'&&!((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A'))){
        s+='1';
    }else{
        s+='0';
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
    return 0;
}





