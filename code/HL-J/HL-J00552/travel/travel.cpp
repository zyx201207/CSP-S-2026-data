#include <bits/stdc++.h>
using namespace std;
int ab[4]={};
void outing(){
    for(int i=0;i<4;i++){
        cout<<ab[i];
    };
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2;
    cin>>c1;//R box
    cin>>s1;//R seat
    cin>>c2;//S box
    cin>>s2;//S seat

    if(c1==c2) ab[0]=1;
    else{
        outing();
        return 0;
    }
    if(s1[0]==s2[0] && s1[1] == s2[1]) ab[1]=1;
    else{
        outing();
        return 0;
    }

    if(s1[2]=='A' && s2[2]=='B'){
        ab[2]=1;
        ab[3]=1;
    }else if(s1[2]=='B' && s2[2]=='A'){
        ab[2]=1;
        ab[3]=1;
    }else if(s1[2]=='B' && s2[2]=='C'){
        ab[2]=1;
        ab[3]=1;
    }else if(s1[2]=='C' && s2[2]=='B'){
        ab[2]=1;
        ab[3]=1;
    }else if(s1[2]=='D' && s2[2]=='F'){
        ab[2]=1;
        ab[3]=1;
    }else if(s1[2]=='F' && s2[2]=='D'){
        ab[2]=1;
        ab[3]=1;
    }else if(s1[2]=='A' && s2[2]=='C'){
        ab[2]=1;
        ab[3]=0;
    }else if(s1[2]=='C' && s2[2]=='A'){
        ab[2]=1;
        ab[3]=0;
    }else{
        outing();
        return 0;
    }


    for(int i=0;i<4;i++){
        cout<<ab[i];
    };

    fclose(stdin);
    fclose(stdout);

    return 0;
}

