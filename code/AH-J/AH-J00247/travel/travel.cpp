#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<1;
        string ss1="aa",ss2="aa";
        ss1[0]=s1[0];
        ss1[1]=s1[1];
        ss2[0]=s2[0];
        ss2[1]=s2[1];
        if(ss1==ss2){
            cout<<1;
            char a,b;
            a=s1[2];
            b=s2[2];
            if(((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C'))||((a=='D'||a=='F')&&(b=='D'||b=='F'))){
                cout<<1;
                if((a=='A'&&b=='B')||(a=='B'&&b=='A')){
                    cout<<1;
                }else if((a=='B'&&b=='C')||(a=='C'&&b=='B')){
                    cout<<1;
                }else if((a=='D'&&b=='F')||(a=='F'&&b=='D')){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<0<<0;
            }
        }else{
            cout<<0<<0<<0;
        }
    }else{
        cout<<0<<0<<0<<0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
