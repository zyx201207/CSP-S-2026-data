#include <bits/stdc++.h>
using namespace std;

string n,x,y;
int n1,n2;
int main(){
    freopen("treval.in","r","stdin");
    freopen("treval.out","w","stdout");
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a == c)n+="1";
    else n+="0";

    int num = b.size()-1;
    for(int i=0;i<num;i++){
        x += b[i];
        y += d[i];
    }
    if(x == y)n+="1";
    else n+="0";

    if(b[num]=='A'&&b[num]=='B'&&b[num]=='C')n1 = 1;
    else n1 = 0;
    if(d[num]=='A'&&d[num]=='B'&&d[num]=='C')n2 = 1;
    else n2 = 0;
    if(n1 == n2)n += "1";
    else n += "0";


    cout << "11" << n;
    return 0;
}
