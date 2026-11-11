#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
using namespace std;
int c1,c2;
int s1a,s2a;
char s1b,s2b;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>c1>>s1a>>s1b>>c2>>s2a>>s2b;
if(c1==c2){
    cout<<1;
}
else{
   cout<<0;
}
if(s1a==s2a&&c1==c2){
        cout<<1;

    }
    else{
        cout<<0;
    }

 if(((s1b=='A'&&s2b=='B')||(s1b=='A'&&s2b=='C')||(s1b=='B'&&s2b=='A')||(s1b=='B'&&s2b=='C')||(s1b=='C'&&s2b=='A')||(s1b=='C'&&s2b=='B')||(s1b=='D'&&s2b=='F')||(s1b=='F'&&s2b=='D'))&&c1==c2&&s1a==s2a){
                cout<<1;

        }
        else{
            cout<<0;
        }
if(((s1b=='A'&&s2b=='B')||(s1b=='B'&&s2b=='C')||(s1b=='D'&&s2b=='F')||(s1b=='A'&&s2b=='B')||(s1b=='C'&&s2b=='B')||(s1b=='F'&&s2b=='D'))&&((s1b=='A'&&s2b=='B')||(s1b=='A'&&s2b=='C')||(s1b=='B'&&s2b=='A')||(s1b=='B'&&s2b=='C')||(s1b=='C'&&s2b=='A')||(s1b=='C'&&s2b=='B')||(s1b=='D'&&s2b=='F')||(s1b=='F'&&s2b=='D'))&&c1==c2&&s1a==s2a){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
return 0;
}
