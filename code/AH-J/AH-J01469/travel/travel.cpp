#include<bits/stdc++.h>
using namespace std;
int main (){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    bool t=0,b=0;
    char p1=s1[0]+s1[1],p2=s2[0]+s2[1],l1=s1[2],l2=s2[2];
    if ((l1=='A'||l1=='B'||l1=='C')&&(l2=='A'||l2=='B'||l2=='C')){
        b=1;
    }else if ((l1=='D'||l1=='F')&&(l2=='D'||l2=='F')){
        b=1;
    }
    if (c1==c2){
        cout << 1;
        t=1;
    }else{
        cout << 0;
    }
    if (p1==p2&&t){
        cout << 1;
    }else{
        cout << 0;
        t=0;
    }
    if (b&&t){
        cout << 1;
    }else{
        cout << 0;
        t=0;
    }
    if ((l1-l2==1||l2-l1==1)&&t){
        cout << 1;
    }else {
        cout << 0;
    }
    return 0;
}
