#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
        cout << 0;
    else
        cout<<1;

    for(int i=1;i<=1;i++){
        if(s1-'A'==s2-'B')
            cout<<1;
        else if(s1-'A'==s2-'C')
            cout<<1;
        else if(s1-'A'==s2-'D')
            cout<<1;
        else if(s1-'A'==s2-'F')
            cout<<1;

        else if(s1-'B'==s2-'A')
            cout<<1;
        else if(s1-'B'==s2-'C')
            cout<<1;
        else if(s1-'B'==s2-'D')
            cout<<1;
        else if(s1-'B'==s2-'F')
            cout<<1;

        else if(s1-'C'==s2-'A')
            cout<<1;
        else if(s1-'C'==s2-'B')
            cout<<1;
        else if(s1-'C'==s2-'D')
            cout<<1;
        else if(s1-'C'==s2-'F')
            cout<<1;

        else if(s1-'D'==s2-'A')
            cout<<1;
        else if(s1-'D'==s2-'B')
            cout<<1;
        else if(s1-'D'==s2-'C')
            cout<<1;
        else if(s1-'D'==s2-'F')
            cout<<1;

        else if(s1-'F'==s2-'A')
            cout<<1;
        else if(s1-'F'==s2-'B')
            cout<<1;
        else if(s1-'F'==s2-'C')
            cout<<1;
        else if(s1-'F'==s2-'D')
            cout<<1;

        else
            cout<<0;
    }
    cout << "00";
    return 0;
}
