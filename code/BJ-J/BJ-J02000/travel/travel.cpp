#include <bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2;
int p1,p2;
char h1,h2;
bool flag1=true;
bool flag2=true;
bool flag3=true;
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) {
        cout<<1;
    }else cout<<0,flag1=false;

    p1=(s1[0]-'0')*10+(s1[1]-'0');
    p2=(s2[0]-'0')*10+(s2[1]-'0');

    h1=s1[2],h2=s2[2];

    if(flag1==true && p1==p2) cout<<1;
    else {
        cout<<0;
        flag2=false;
    }
    if(flag1==false) cout<<0;
    else if(flag1==true && flag2==false) cout<<0;
    else if(flag1==true && flag2==true){
        if((h1=='A'||h1=='B'||h1=='C')){
            if(h2=='D'||h2=='F'){
                cout<<0,flag3=false;
            }else cout<<1;
        }else if(h1=='D'||h1=='F'){
            if(h2=='A'||h2=='B'||h2=='C'){
                cout<<0,flag3=false;
            }else cout<<'B'<<1;
        }
    }

    if(flag1==false) cout<<0;
    else if(flag1==true && flag2==false) cout<<0;
    else if(flag1==true && flag2==true){
        if(flag3==false) cout<<0;
        else if((h1=='A'&&h2=='B')||(h1=='B'&&h2=='A')||
                (h1=='B'&&h2=='C')||(h1=='C'&&h2=='B')||
                (h1=='D'&&h2=='F')||(h1=='F'&&h2=='D')){
                    cout<<1;
        }else cout<<0;
    }
    return 0;
}
