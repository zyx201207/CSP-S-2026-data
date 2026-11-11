#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a,b;
    string s1,s2;
    cin>>a>>s1>>b>>s2;
    if(a==b){
        cout<<1;
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            cout<<1;
            if(((int)s1[2]<=67 && (int)s2[2]<=67) || ((int)s1[2]>67 && (int)s2[2]>67)){
                cout<<1;
                if(abs((int)s1[2]-(int)s2[2])==1) cout<<1;
                else cout<<0;
            }
            else cout<<0<<0;
        }
        else cout<<0<<0<<0;
    }
    else cout<<0<<0<<0<<0;
    return 0;
}
