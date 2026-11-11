#include <bits/stdc++.h>
using namespace std;

int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int w=0;
    int c1,s1;
    string c2,s2;
    cin>>c1>>c2>>s1>>s2;
    if(c1==s1){
        cout<<1;
        w++;
    }
    else cout<<0;


    if(w==1){
        if(c2[0]==s2[0]&&c2[1]==s2[1]){
            cout<<1;
            w++;

        }
        else{
            cout<<0;
        }
    }
    else{
        cout<<0;
    }

    if(w==2){
        if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'){
            if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
                cout<<1;
                w++;
            }
            else{
                cout<<0;
            }
    }
        if(c2[2]=='D'||c2[2]=='F'){
            if(s2[2]=='D'||s2[2]=='F'){
                cout<<1;
                w++;
            }
            else{
                cout<<0;
            }
        }
    }
    else{
        cout<<0;
    }

    if(w==3){
        if(c2[2]=='A'&&s2[2]=='B'){
            cout<<1;
        }
        else if(c2[2]=='B'&&s2[2]=='A'){
            cout<<1;
        }
        else if(c2[2]=='B'&&s2[2]== 'C'){
            cout<<1;
        }
        else if(c2[2]=='C'&&s2[2]== 'B'){
            cout<<1;
        }
        else if(c2[2]=='D'&&s2[2]== 'F'){
            cout<<1;
        }
        else if(c2[2]=='F'&&s2[2]== 'D'){
            cout<<1;
        }
        else{
            cout<<0;
        }

    }
    else{
        cout<<0;
    }



    return 0;
}
