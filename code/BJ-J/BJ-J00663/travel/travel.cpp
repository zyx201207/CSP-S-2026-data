#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    char c[4];
    char d[4];
    cin >> a;
    for(int i=0;i<=3;i++){
        cin>>c[i];
    }
    cin>>b;
    for(int i=0;i<=3;i++){
        cin>>d[i];
    }

    if(a==b){
        cout<<1;
    }
    else{
        cout<<0;
    }

    if(c[1]==d[1]&&c[0]==d[0]){
        cout<<1;
    }
    else{
        cout<<0;
    }

    if(((c[2]==A||c[2]==B||c[2]==C)&&(d[2]==A||d[2]==B||d[2]==C))||((c[2]==D||c[2]==F)&&(d[2]==D||d[2]==F))){
        cout<<1;
    }
    else{
        cout<<0;
    }

    if((c[2]==A&&d[2]==B)||(c[2]==B&&d[2]==A)||(c[2]==B&&d[2]==C)||(c[2]==C&&d[2]==B)){
        cout<< 1;
    }
    else if((c[2]==D&&d[2]==F)||(c[2]==F&&d[2]==D)){
        cout<< 1;
    }
    else{
        cout<<0;
    }

    return 0;

}