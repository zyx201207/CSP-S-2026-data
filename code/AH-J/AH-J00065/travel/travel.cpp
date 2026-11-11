#include <bits/stdc++.h>
using namespace std;
//Trick||Treat!
string a,b,c,d;
int main(){
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    cin >> a >> b >> c >> d;
    if(a != c)  cout << "0000";
    else{
        cout << 1;
        string s1 = "",s2 = "";
        s1 += b[0], s1 += b[1];
        s2 += d[0], s2 += d[1];
        if(s1 == s2)    cout << 1;
        else{cout <<"000";return 0;}
        if((b[2] <= 'C' && b[2] >= 'A' && d[2] <= 'C' && d[2] >= 'A' )|| (b[2] <= 'F' && b[2] >= 'D' && d[2] <= 'F' && d[2] >= 'D' ))   cout << 1;
        else{cout <<"00";return 0;}
        if(abs(d[2]-b[2]) == 1) cout <<1;
        else    cout << 0;
    }
    return 0;
}
