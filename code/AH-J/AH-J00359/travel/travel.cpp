#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>s1>>c1>>s2>>c2;

if(s1==s2){
    cout<<1;
    int a1,a2;
    a1=(c1[0]-'0')*10+(c1[1]-'0');
    a2=(c2[0]-'0')*10+(c2[1]-'0');
    if(a1==a2){
        cout<<1;
        char b1=c1[2];
        char b2=c2[2];
        bool falg1,falg2;
        if(b1>='A'&&b1<='C'){
             falg1=1;
        }else{
             falg1=0;
        }
        if(b2>='A'&&b2<='C'){
             falg2=1;
        }else{
             falg2=0;
        }
        if(falg2==falg1){
            cout<<1;
            int t1=b1-'0';
            int t2=b2-'0';
            if(abs(t1-t2)==1){
                cout<<1;
            }else{
                cout<<0;
            }
        }else{
            cout<<"00";
        }
    }else{
        cout<<"000";
    }
}else{
    cout<<"0000";
}
return 0;
}














