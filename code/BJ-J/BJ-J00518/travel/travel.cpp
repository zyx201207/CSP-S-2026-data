#include<bits/stdc++.h>

using namespace std;

string s1,s2,c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>>c1>>s1>>c2>>s2;
    int f1=0,f2=0,f3=0,f4=0;
    if(c1==c2){
        f1=1;
    }

    if(f1 && s1[0]==s2[0] && s1[1]==s2[1]){
        f2=1;
    }

    if(f2 &&  ((('A'<=s1[2] && s1[2]<='C') && ('A'<=s2[2] && s2[2]<='C')) || ('D'<=s1[2] && s1[2]<='F') && ('D'<=s2[2] && s2[2]<='F'))){
        f3=1;
    }

    if(f3 && ((s1[2]-s2[2]==1) || (s1[2]-s2[2]==-1))){
        f4=1;
    }
    else if(f3 && ('D'<=s1[2] && s1[2]<='F')){
        f4=1;
    }

    cout<<f1<<f2<<f3<<f4;
    return 0;
}
