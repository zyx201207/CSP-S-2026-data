#include<bits/stdc++.h>
using namespace std;
string s,s1,s2,s3;
bool cmp(char a,char b){
    if((a=='D')||(b=='D')){
     //   cout<<"123"<<endl;
        if((a=='F')||(b=='F')){
            return true;
        }
    }
    if((a=='F')||(b=='F')){
     //   cout<<"1234"<<endl;
        if((a=='D')||(b=='D')){
            return true;
        }
    }
    if((a=='A')||(b=='A')){
     //   cout<<"12345"<<endl;
        if((a=='C')||(b=='C')||(a=='B')||(b=='B')){
            return true;
        }
    }
    if((a=='C')||(b=='C')){
     //   cout<<"123456"<<endl;
        if((a=='A')||(b=='A')||(a=='B')||(b=='B')){
            return true;
        }
    }
    if((a=='B'||b=='B')){
     //   cout<<"1234567"<<endl;
        if((a=='C')||(b=='C')||(a=='A')||(b=='A')){
            return true;
        }
    }
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s>>s1>>s2>>s3;
    int j=0,a=0,a1=0,b=0,b1=0,c2,d;
    char k,l;
    a=(s[0]-'0')*10+(s[1]-'0');
    b=(s1[0]-'0')*10+(s1[1]-'0');
    c2=(s2[0]-'0')*10+(s2[1]-'0');
    d=(s3[0]-'0')*10+(s3[1]-'0');
    k=s1[2],l=s3[2];
    if(a!=c2){
     //   cout<<c2<<' '<<d<<endl;
        cout<<"0000";
    }
    else if(b!=d){
        cout<<"1000";
    }
    else if(!cmp(k,l)){
        cout<<"1100";
        cout<<cmp(k,l)<<endl;
    }
    else if(!(k+1==l||k-1==l)){
        cout<<"1110";
    }
    else{
        cout<<"1111";
    }







return 0;
}
