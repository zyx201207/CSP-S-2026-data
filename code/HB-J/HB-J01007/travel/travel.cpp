#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
string c1,s1,c2,s2;
int n1=0,n2=0,n3=0,n4=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1[0]==c2[0]&&c1[1]==c2[1])n1=1;
    if(n1==1){
        if(s1[0]==s2[0]&&s1[1]==s2[1])n2=1;
        if(n2==1){
            if(s1[2]=='A'&&s2[2]=='B')n3=1,n4=1;
            else if(s1[2]=='A'&&s2[2]=='C')n3=1;
            else if(s1[2]=='B'&&s2[2]=='A')n3=1,n4=1;
            else if(s1[2]=='B'&&s2[2]=='C')n3=1,n4=1;
            else if(s1[2]=='C'&&s2[2]=='A')n3=1;
            else if(s1[2]=='C'&&s2[2]=='B')n3=1,n4=1;
            else if(s1[2]=='D'&&s2[2]=='F')n3=1,n4=1;
            else if(s1[2]=='F'&&s2[2]=='D')n3=1,n4=1;
            }
    }

    cout<<n1<<n2<<n3<<n4;
    return 0;
}
