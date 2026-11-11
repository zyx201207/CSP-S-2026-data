#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<"1";
    if(s1[0]!=s2[0]||s1[1]!=s2[1]){
        cout<<"000";
        return 0;
    }
    cout<<"1";
    char a=s1[2],b=s2[2];
    if(!((a<='C'&&b<='C')||(a>='D'&&b>='D'))){
        cout<<"00";
        return 0;
    }
    cout<<"1";
    if(a>='A'&&a<='C'&&b>='A'&&b<='C'){
    	if(abs((int)(a-b))!=1) cout<<"0";
    	else cout<<"1";
	}else{
		if(a=='D'&&b=='F') cout<<"1";
		else if(a=='F'&&a=='D') cout<"1";
		else cout<<"0";
	}
    return 0;
}
