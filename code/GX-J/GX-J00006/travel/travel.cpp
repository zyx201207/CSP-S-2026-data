#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    vector <string> x,y;
    string temp;
    for(int i =0;i<2;i++){
        cin >>temp;
        x.push_back(temp);
    }
    for(int i =0;i<2;i++){
        cin >>temp;
        y.push_back(temp);
    }
    int a=0,b=0,c=0,d=0;
    if(x[0] == y[0]) a=1;
    if(x[1][0]==y[1][0] && x[1][1] == y[1][1]) b=1;
    if(x[1][2]=='A' || x[1][2]=='B'||x[1][2]=='C'){
        if(y[1][2]=='A'||y[1][2]=='B'||y[1][2]=='C')c =1;
    }
    if(x[1][2]=='D' || x[1][2]=='F'){
        if(y[1][2]=='F'||y[1][2]=='D') c=1;
    }
    if((x[1][2] == 'A' &&y[1][2]=='B')||(x[1][2] == 'B' &&y[1][2]=='C')||(x[1][2] == 'D' &&y[1][2]=='F')) d = 1;
    if((y[1][2] == 'A' &&x[1][2]=='B')||(y[1][2] == 'B' &&x[1][2]=='C')||(y[1][2] == 'D' &&x[1][2]=='F')) d = 1;
    cout <<a<<b<<c<<d;
    return 0;
}
