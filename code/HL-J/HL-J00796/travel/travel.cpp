#include <bits/stdc++.h>
using namespace std;
int a,d,q1,q2;
string s,s1;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a>>s>>d>>s1;
if(a==d){
	cout<<"1";
}else{
	cout<<"0000";
	return 0;
}
for(int i=0; i<=1; i++){
	q1+=s[i];
	q2+=s[i];
}
if(q1==q2){
        cout<<"1";
    }else{
        cout<<"000";
}
    if(s[2]>='A'&&s[2]<='C'){
        if(s1[2]>='A'&&s1[2]<='C'){
            cout<<"1";
    }else{
            cout<<"00";
            return 0;
}
    }else{
    if(s1[2]>='D'&&s1[2]<='F'){
            cout<<"11";
            return 0;
    }else{
            cout<<"00";
            return 0;
    }
}
if(s[2]=='A'&&s1[2]=='B'){
    cout<<"1";
    return 0;
}
if(s[2]=='B'){
    cout<<"1";
    return 0;
}
if(s[2]=='C'&&s1[2]=='B'){
    cout<<"1";
    return 0;
}
cout<<"0";
return 0;
}
