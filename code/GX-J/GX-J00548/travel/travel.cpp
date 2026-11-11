#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;

    int cc=1;

    if(c1==c2)cout<<1;
    else{
        cout<<0;
        cc=0;
    }

    int bb=1;

    if(cc==1){
        if((s1[0]+s1[1])==(s2[0]+s2[1]))cout<<1;
        else{
            cout<<0;
            bb=0;
        }
    }
    else if(cc==0)cout<<0;
    else cout<<"";

    if(cc==1&&bb==1){
        if((s1[2]=='F'||s1[2]=='D')&&(s2[2]=='F'||s2[2]=='D'))cout<<1;
        else if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))cout<<1;
        else cout<<0;
    }
    else if(cc==0||bb==0)cout<<0;
    else cout<<"";

    int aa=1;

    if(bb==1&&cc==1){
        if(s1[2]=='D'){
            if(s2[2]=='F'){
                cout<<1;
                aa=0;
            }
        }
        else if(s1[2]=='F'){
            if(s2[2]=='D'){
                cout<<1;
                aa=0;
            }
        }
        else if(s1[2]=='A'){
            if(s2[2]=='B'){
                cout<<1;
                aa=0;
            }
        }
        else if (s1[2]=='B'){
            if(s2[2]=='A'||s2[2]=='C'){
                cout<<1;
                aa=0;
            }
        }
        else if(s1[2]=='C'){
            if(s2[2]=='B'){
                cout<<1;
                aa=0;
            }
        }
        if(aa==1)cout<<0;
    }
    else if(bb==0||cc==0)cout<<0;
    else cout<<"";

    return 0;
}
