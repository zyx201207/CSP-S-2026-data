#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    cin>> a >> b >> c >> d;
    int n=0,f=0,cnt=0,h=0,t=0;


    for(int i=0;i<2;i++){
        if(a[i]==c[i]){n++;}

    }
    if(n==2){
        cout<< 1;
        n=0;
    }
    else{cout<<0000;}
    for(int i=0;i<3;i++){
        if(b[i]==d[i]){n++;}
        if(b[i]<='D'&&d[i]<='D'){f=1;}
        if(b[i]+1==d[i]||b[i]-1==d[i]){cnt=1;}
        if(b[i]>='D'||b[i]<='F'&&d[i]>='D'||d[i]<='F'){f=1;}
        if(b[i]>='D'){h++;}
        else{h=0;}
        if(d[i]>='D'){t++;}
        else{t=0;}


    }
    if(n==2){cout<< 1;}
    if(t==h){f=1;}
    else{f=0,cnt=0;}
    cout << f << cnt;


    return 0;
}

