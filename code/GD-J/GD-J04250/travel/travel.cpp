#include<bits/stdc++.h>
using namespace std;
string b,c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        char p1=s1[0],g1=s1[1];
        char p2=s2[0],g2=s2[1];
        if(p1==p2&&g1==g2){
            cout<<"1";
            int a1=s1[2]-'A';
            int a2=s2[2]-'A';
            if(a1<=2&&a2<=2||a1>2&&a2>2){
                cout<<"1";
                if(a1-a2==1||a2-a1==1||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
                    cout<<"1";
                }
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
}

