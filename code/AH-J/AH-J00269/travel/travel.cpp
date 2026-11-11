#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c1,c2;
string s1,s2,hh1,hh2;
bool t[6]={1,1,1,0,0,0};
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
    }else{
        cout<<1;
        hh1=s1.substr(0,2);
        hh2=s2.substr(0,2);
        if(hh1!=hh2){
            cout<<"000";
        }else{
            cout<<1;
            if(t[s1[2]-'A']!=t[s2[2]-'A']){
                cout<<"00";
            }else{
                cout<<1;
                if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }
        }
    }
    return 0;
}
