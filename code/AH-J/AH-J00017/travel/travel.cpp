#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M = 1e5+5;
string c1,c2,w1,w2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    //int t0=clock();///

    cin >> c1 >> w1 >> c2 >> w2;
    string h1 = w1.substr(0,2);
    string h2 = w2.substr(0,2);

    if(c1!=c2) cout << "0000";
    else if(h1!=h2) cout << "1000";
    else if(h1==h2)
    {
        if(w1[2]>='A'&&w1[2]<='C' && w2[2]>='A'&&w2[2]<='C')
        {
            if(abs(w1[2]-w2[2])<=1) cout << "1111";
            else cout << "1110";
        }
        else if(w1[2]>='D'&&w1[2]<='F' && w2[2]>='D'&&w2[2]<='F') cout << "1111";
        else cout << "1100";
    }

    //cout << "\ntimeuse:" << clock()-t0 << "ms";///
    cout << endl;
    return 0;
}
