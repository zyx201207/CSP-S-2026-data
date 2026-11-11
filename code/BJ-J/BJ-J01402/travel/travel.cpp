#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
map<char,int> mp;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mp['A'] = 1; mp['B'] = 2; mp['C'] = 3; mp['D'] = 6; mp['F'] = 7;
    string c1,c2,s1,s2; cin>>c1>>s1>>c2>>s2;
    if(c1 == c2)
    {
        cout<<1;
        int x1 = (s1[0]-'0')*10+(s1[1]-'0');
        int x2 = (s2[0]-'0')*10+(s2[1]-'0');
        if(x1 == x2)
        {
            cout<<1;
            if(((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C')&&(s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')) || ((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')))
            {
                cout<<1;
                if(abs(mp[s1[2]]-mp[s2[2]]) == 1) cout<<1<<endl;
                else cout<<"0"<<endl;
            }
            else cout<<"00"<<endl;
        }
        else cout<<"000"<<endl;
    }
    else cout<<"0000"<<endl;
    return 0;
}
