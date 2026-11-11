#include<bits/stdc++.h>

using namespace std;

bool aa(char a,char b){

    if((a+1==b and a!='C') or (b+1==a and b!='C')){

        return 1;

    }else if(a=='A' and b=='C'){

        return 1;

    }

    return 0;

}

int main(){

    freopen("travel.in","r",stdin);

    freopen("travel.out","w",stdout);

    string s1,s2,s3,s4;

    cin>>s1>>s2>>s3>>s4;

    if(s1==s3){

        cout<<1;

    }else{

        cout<<"0000";

        return 0;

    }

    if(s2[0]==s4[0] and s2[1]==s4[1]){

        cout<<1;

    }else{

        cout<<"000";

        return 0;

    }

    if(aa(s2[2],s4[2])){

        cout<<1;

    }else{

        cout<<"00";

        return 0;

    }

    if((char(s2[2]+1)==s4[2] and s2[2]!='C') or (char(s2[2]+1)==s4[2] and s4[2]!='C')){

        cout<<1;

    }else{

        cout<<0;

        return 0;

    }

    return 0;

}
