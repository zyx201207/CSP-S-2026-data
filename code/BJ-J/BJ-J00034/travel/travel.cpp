#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    cout<<1;
    char sa[3],sb[3];
    sa[0]=s1[0],sb[0]=s2[0];
    sa[1]=sa[1],sb[1]=s2[1];
    if(sa!=sb){
        cout<<"000";
        return 0;
    }
    cout<<1;
    char c=s1[2],d=s2[2];
    if(!('A'<=c&&c<='C'&&'A'<=d&&d<='C')){
        if(!('D'<=c&&c<='F'&&'D'<=d&&d<='F')){
            cout<<"00";
            return 0;
        }
    }
    cout<<1;
    if(abs(c-d)==1||('D'==c&&d=='F')||('D'==d&&c=='F'))cout<<1;
    else cout<<0;
    return 0;
}