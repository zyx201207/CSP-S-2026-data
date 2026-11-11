#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char a,b,c,d;
    int s=0;
    cin.getline(a,1000);
    cin.getline(b,1000);
    cin.getline(c,1000);
    cin.getline(d,1000);
    if(a==c){
        cout<<"1";
    }
    for(int i=0;i<strlen(a)-1;i++){
        if(b[i]==d[i]){
            s++;
        }
    }
    if(s==2){
        cout<<"1";
    }
    for(int i=strlen(b);i>2;i--){
        if(b[i]>='A'&&b[i]<='C'&&d[i]>='A'&&d[i]<='C'){
            cout<<"1";
        }
        else if(b[i]=='D'||b[i]=='F'&&d[i]=='D'||d[i]=='F'){
            cout<<"1"<<"1";
        }
    }
    for(int i=0;i<strlen(b)-1;i++){
        if(b[i]==d[i]){
            for(int i=strlen(b);i>2;i--){
                if(b[i]-d[i]==1){
                    if(b[i]!='C'&&d[i]!='D'||b[i]!='D'&&d[i]!='C'){
                            cout<<"1";
                    }
                }
            }
        }
    }

    return 0;
}
