#include <bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in","w",stdin);
    //freopen("travel.out","r",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;

    int a,b;
    a=10*(s1[0]-'0')+(s1[1]-'0');
    b=10*(s2[0]-'0')+(s2[1]-'0');

    int x,y;
    x=s1[2]-'A';
    y=s2[2]-'A';

    if(c1==c2){
        cout<<1;
        if(a==b){
        cout<<1;
        if((x>2 && y>2) || (x<=2 && y<=2)){
        cout<<1;
        if(x-y==1 || y-x==1)
            cout<<1;
        else
            cout<<0;
        }
    else
        cout<<0<<0;
        }
    else
        cout<<0<<0<<0;

    }
    else
        cout<<0<<0<<0<<0;


return 0;
}
