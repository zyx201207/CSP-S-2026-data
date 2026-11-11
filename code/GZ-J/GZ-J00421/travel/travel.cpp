#include<bits/stdc++.h>
using namespace std;

int main(){
    default("travel.in","r");
    default("travel.out","w");
    string c1,s1,c2,s2,a=0,b=0,c=0,d=0,e=0;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        b=1;
    }
    if(b==1 and s1[0]==s2[0] and s1[1]==s2[1]){
        c=1;
    }
    if(c==1 and (s1[2]<=C and s2[1]<=C) or (s1[1]<=E and s1[1]>=D and s2[1]<=E and s2[1]>=D)){
        d=1;
    }
    if(d==1 and (s1[2]==s2[2] and s1[0:1]==s2[0:1]-1 or s1[0:1]==s2[0:1]+1) or (s1[0:1]==s2[0:1] and s1[2]==s2[2]-1 or s1[2]==s2[2]+1)){
        e=1;
    }
    if(e==1){a=4;return 0;
    }else if(d==1){a=3;return 0;
    }else if(c==1){a=2;return 0;
    }else if(b==1){a=1;return 0;
    }else if(1==1){a=0;return 0;
    }cout<<'1'*a<<'0'*(4-a)<<endl;

    return 0;
}
