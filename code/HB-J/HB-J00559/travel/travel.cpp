#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a1,a2;
    string c1,c2;
    cin >> a1 >> c1 >> a2 >> c2;
    bool a=0,b=0,c=0,d=0;

    if(a1==a2) a=1;

    if(a==1){
        int c3=(int(c1[0])-48)*10+int(c1[1])-48;
        int c4=(int(c2[0])-48)*10+int(c2[1])-48;
        if(c3==c4) b=1;
    }

    int c5=int(c1[2])-64;
    int c6=int(c2[2])-64;
    if(b==1){
        if(c5>=1 && c5<=3 && c6>=1 && c6<=3) c=1;
        if(c5>=4 && c5<=5 && c6>=4 && c6<=5) c=1;
    }

    if(c==1){
        if(c5==c6-1 || c5==c6+1) d=1;
    }
    cout << a << b << c << d;
    return 0;
}
