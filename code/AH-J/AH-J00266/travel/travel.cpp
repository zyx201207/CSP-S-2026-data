#include<bits/stdc++.h>
using namespace std;//great
string c1,s1,c2,s2;
int f1(){
    return c1==c2; 
}
int f2(){
    string a1=s1.substr(0,2);
    string a2=s2.substr(0,2);
    return a1==a2;
}
int f3(){
    string b1=s1.substr(2,1);
    string b2=s2.substr(2,1);
    return b1[0]>='A'&&b1[0]<='C'&&b2[0]>='A'&&b2[0]<='C'||b1[0]>='D'&&b1[0]<='F'&&b2[0]>='D'&&b2[0]<='F';
}
int f4(){
    string b1=s1.substr(2,1);
    string b2=s2.substr(2,1);
    if(b1=="A"){
        if(b2=="B") return 1;
        return 0;
    }else if(b1=="B"){
        if(b2=="A"&&b2!="C") return 1;
        return 0;
    }else if(b1=="C"){
        if(b2=="B") return 1;
        return 0;
    }else if(b1=="D"){
        if(b2=="F") return 1;
        return 0;
    }else if(b1=="F"){
        if(b2=="D") return 1;
        return 0;
    }
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(f1()) cout<<1;
    else cout<<0;
    if(f1()&&f2()) cout<<1;
    else cout<<0;
    if(f1()&&f2()&&f3()) cout<<1;
    else cout<<0;
    if(f1()&&f2()&&f3()&&f4()) cout<<1;
    else cout<<0;
    return 0;
}
