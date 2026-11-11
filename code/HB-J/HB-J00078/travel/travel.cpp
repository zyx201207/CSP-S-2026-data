#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s;
    char x,y;
    cin>>a;
    cin>>s;
    int len = s.size();
    for(int i = 0;i < len;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            b = b * 10 + (s[i] - '0');
        }
        else x = s[i];
    }
    cin>>c;
    cin>>s;
    len = s.size();
    for(int i = 0;i < len;i++){
        if(s[i] >= '0' && s[i] <= '9'){
            d = d * 10 + (s[i] - '0');
        }
        else y = s[i];
    }
    if(a == c) cout<<"1";
    else cout<<"0";
    if(a == c && b == d) cout<<"1";
    else cout<<"0";
    if(a == c && b == d && ((x <= 'C' && y <= 'C') || (x >= 'D' && y >= 'D'))) cout<<"1";
    else cout<<"0";
    if(a == c && b == d && ((x <= 'C' && y <= 'C') || (x >= 'D' && y >= 'D')) && abs((int)(x - y)) == 1) cout<<"1";
    else cout<<"0";
    //cout<<"\n"<<a<<" "<<b<<" "<<c<<" "<<d<<" ";
    return 0;
}
