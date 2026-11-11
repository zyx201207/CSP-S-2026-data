#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n=3,c1,c2;
    string s1,s2;
    x[1000];
    y[1000];
    cin>>c1>>s1>>c2>>s2;
    for(int i=1;i<=n;i++){
        if(c1!=c2)
        cout<<"0000";

        else if(c1==c2&&x[i]==y[i])
            cout<<"1111";
        else if(c1==c2&&x[i]!=y[i])
            cout<<"1110";

        else if(c1==c2&&x[i]-y[i]>=10)
            cout<<"1100";

        else cout<<"1000";
    }

    return 0;
}
