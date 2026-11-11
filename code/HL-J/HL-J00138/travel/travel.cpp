#include<bits/stdc++.h>
using namespace std;
struct node{
    string c,s;
};
node r,x;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>r.c>>r.s>>x.c>>x.s;
    if(r.c!=x.c){
        cout<<"0000";
        return 0;
    }
    else{
        if(r.s[0]!=x.s[0]||r.s[1]!=x.s[1]){
            cout<<"1000";
            return 0;
        }
        else{
            if(r.s[2]=='A'||r.s[2]=='B'||r.s[2]=='C')
            {
                if(x.s[2]=='D'||x.s[2]=='E')
                {
                    cout<<"1100";
                    return 0;
                }
                else{
                if(abs(int(r.s[2]-x.s[2]))!=1)
                {
                    cout<<"1110";
                    return 0;
                }
                else cout<<"1111";
                }
            }
            else if(x.s[2]=='A'||x.s[2]=='B'||x.s[2]=='C')
            {
                if(r.s[2]=='D'||r.s[2]=='E')
                {
                    cout<<"1100";
                    return 0;
                }
                else{
                if(abs(int(r.s[2]-x.s[2]))!=1)
                {
                    cout<<"1110";
                    return 0;
                }
                else cout<<"1111";
                }
            }

        }
    }

    return 0;
}
