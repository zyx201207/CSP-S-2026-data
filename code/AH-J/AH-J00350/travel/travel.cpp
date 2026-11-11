#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
    }else{
        cout<<1;
        string p1=s1.substr(0,2);
        string p2=s2.substr(0,2);
        if(p1!=p2){
            cout<<"000";
        }else{
            cout<<1;
            string z1=s1.substr(2,1);
            string z2=s2.substr(2,1);
            int zz1,zz2;
            if(z1[0]=='A'||z1[0]=='B'||z1[0]=='C') zz1=1;
            else zz1=2;
            if(z2[0]=='A'||z2[0]=='B'||z2[0]=='C') zz2=1;
            else zz2=2;
            if(zz1!=zz2){
                cout<<"00";
            }else{
                cout<<1;
                if(int(z1[0])-int(z2[0])==1||int(z1[0])-int(z2[0])==-1||z1[0]=='D'&&z2[0]=='F'||z2[0]=='D'&&z1[0]=='F'){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }
        }
    }
    return 0;
}

