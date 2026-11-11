#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2){
        cout << 1;
    }else{
        cout << 0;
    }
    char seat=s1[0],seat2=s2[0],seat3=s1[1],seat4=s2[1];
    bool flag=false;
    if(c1==c2&&seat==seat2&&seat3==seat4){
            cout << 1;
            flag=true;
    }
    else cout << 0;
    char k=s1[2],k1=s2[2];
    if(((k=='A'&&(k1=='B'||k1=='C'))||(k=='B'&&(k1=='A'||k1=='C'))||(k=='C'&&(k1=='B'||k1=='A'))||(k=='D'&&k1=='F')||(k=='F'&&k1=='D'))&&flag){
        cout << 1;
    }else cout << 0;
    bool flag1=(k=='A'&&k1=='B')||(k=='B'&&(k1=='A'&&k1=='C'))||(k=='C'&&k1=='B')||(k=='D'&&k1=='F')||(k=='F'&&k1=='D');
    if(c1==c2&&seat==seat2&&flag1)cout << 1 << endl;
    else cout << 0 << endl;
}
