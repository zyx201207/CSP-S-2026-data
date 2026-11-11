#include<bits/stdc++.h>
using namespace std;
int main(){
        //freopen("travel.in","r",stdin);
        //freopen("travel.out","w",stdout);
        int a;
        cin>>a;
        char b;
        cin>>b;
        int c;
        cin>>c;
        char d;
        cin>>d;
        if(a==c) cout<<"1";
        else cout<<"0";
        if(b>d&&b-d==1) cout<<"111";
        else if(d>b&&d-b==1) cout<<"111";

        return 0;
}
