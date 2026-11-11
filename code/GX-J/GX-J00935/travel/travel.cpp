#include<bits/stdc++.h>
using namespace std;
string x,x2,y,y2,k;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> x >> x2 >> y >> y2;
    if(x!=y){
        cout << "0000";
        return 0;
    }else{
        cout << 1;
    }

    if(x2[1]==y2[1]){
        cout << 1;
    }else{
        cout << 0;
    }

    if(x2[2]=='A'||x2[2]=='B'||x2[2]=='C'&&y2[2]=='A'||y2[2]=='B'||
       y2[2]=='C'||x2[2]=='D'||x2[2]=='F'&&y2[2]=='D'||y2[2]=='F'){
           if(x2[1]==y2[1]){
                cout << 1;
           }else{
                cout << 0;
           }
    }else{
        cout << 0;
    }

    if(x2[2]=='A'&&y2[2]=='B'||x2[2]=='B'&&y2[2]=='C'||x2[2]=='D'&&y2[2]=='F'||
       y2[2]=='A'&&x2[2]=='B'||y2[2]=='B'&&x2[2]=='C'||y2[2]=='D'&&x2[2]=='F'){
           if(x2[1]==y2[1]){
                cout << 1;
           }else{
                cout << 0;
           }
    }else{
        cout << 0;
    }
    cout << k;
    return 0;
}

