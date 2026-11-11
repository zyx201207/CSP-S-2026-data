#include<bits/stdc++.h>
using namespace std;
void aaa(char q,char p){
    if(q=='A' && p=='B'){
        cout<<"1";
    }
    else if(q=='B' && p=='A'){
        cout<<"1";
    }
    else if(q=='B' && p=='C'){
        cout<<"1";
    }
    else if(q=='C' && p=='B'){
        cout<<"1";
    }
    else if(q=='D' && p=='F'){
        cout<<"1";
    }
    else if(q=='F' && p=='D'){
        cout<<"1";
    }
    else {
        cout<<"0";
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long a,x;
    char b[5]={" "},y[5]={" "};
    cin>>a>>b>>x>>y;
    if(a==x){
        cout<<"1";
        if(b[0]==y[0] && b[1]==y[1]){
            cout<<"1";
            if(b[2]=='A' || b[2]=='B' || b[2]=='C'){
                if(y[2]=='D' || y[2]=='F'){
                    cout<<"00";
                }
                else{
                    cout<<"1";
                    aaa(b[2],y[2]);
                }
            }
            else{
                if(y[2]=='A' || y[2]=='B' || y[2]=='C'){
                    cout<<"00";
                }
                else{
                    cout<<"1";
                    aaa(b[2],y[2]);
                }
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
