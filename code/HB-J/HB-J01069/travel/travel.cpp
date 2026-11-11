#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2,amax,amin;
int a;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
    }else{
        cout<<'1';
        if(s1[0]!=s2[0]||s1[1]!=s2[1]){
            cout<<"000";
        }else{
            cout<<'1';
            amax=max(s1[2],s2[2]);
            amin=min(s1[2],s2[2]);
            a=amax[0]-amin[0];
            if(amax[0]=='D'&&amin[0]=='C'&&a!=1){
                cout<<"00";
            }else{
                cout<<'1';
                if(a!=1){
                    cout<<'0';
                }else{
                    cout<<'1';
                }
            }

        }
        return 0;
    }

}
