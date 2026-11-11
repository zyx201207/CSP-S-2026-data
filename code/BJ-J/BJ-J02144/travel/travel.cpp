#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    char s1[4],s2[4];
    cin >> c1;
    for(int i=1;i<=3;i++) cin >> s1[i];
    cin >> c2;
    for(int i=1;i<=3;i++) cin >> s2[i];
    //1
    if(c1==c2) cout << "1";
    else cout << "0";
    //2
    int flag=0;
    if(c1==c2){
        for(int i=1;i<=2;i++){
            if(s1[i]==s2[i]){
                flag=1;
            }else flag=0;
        }
        if(flag==1) cout << "1";
        else cout << "0";
    }else cout << "0";
    //3
    if(flag==1){
        if(s1[3]=='A'){
            if(s2[3]=='B') cout << "1";
            else if(s2[3]=='C') cout << "1";
            else cout << "0";
        }else if(s1[3]=='B'){
            if(s2[3]=='A') cout << "1";
            else if(s2[3]=='B') cout << "1";
            else cout << "0";
        }else if(s1[3]=='C'){
            if(s2[3]=='A') cout << "1";
            else if(s2[3]=='B') cout << "1";
            else cout << "0";
        }else if(s1[3]=='D'){
            if(s2[3]=='F') cout << "1";
            else cout << "0";
        }else if(s1[3]=='F'){
            if(s2[3]=='D') cout << "1";
            else cout << "0";
        }
    }else cout << "0";
    //4
    if(flag==1){
        if(s1[3]=='A'){
            if(s2[3]=='B') cout << "1";
            else cout << "0";
        }else if(s1[3]=='B'){
            if(s2[3]=='A') cout << "1";
            else if(s2[3]=='C') cout << "1";
            else cout << "0";
        }else if(s1[3]=='C'){
            if(s2[3]=='B') cout << "1";
            else cout << "0";
        }else if(s1[3]=='D'){
            if(s2[3]=='F') cout << "1";
            else cout << "0";
        }else if(s1[3]=='F'){
            if(s2[3]=='D') cout << "1";
            else cout << "0";
        }
    }else cout << "0";

    return 0;
}
