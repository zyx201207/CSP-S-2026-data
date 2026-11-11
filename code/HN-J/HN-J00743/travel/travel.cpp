#include<iostream>
#include<cstdio>
using namespace std; 
string c1,s1,c2,s2;
string c;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
	int a=s1[2],b=s2[2];
	if(c1==c2){
	    c+='1';	 
    }else c+='0';
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
    	c+='1';
	}else c+='0';
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&a<=67&&b<=67){
    	c+='1';
	}else if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&a>67&&b>67){
		c+='1';
	}else c+='0';
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&a<=67&&b<=67&&a-b==1){
    	c+='1';
	}else if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&a<=67&&b<=67&&b-a==1){
		c+='1';
	}else if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&a>67&&b>67&&a-b==1){
		c+='1';
	}else if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&a>67&&b>67&&b-a==1){
		c+='1';
	}else c+='0';
	cout<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

