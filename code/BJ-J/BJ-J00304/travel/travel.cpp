#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1 , s1 , c2 , s2;
    cin>>c1>>s1>>c2>>s2;
    int a=(c1==c2);
    int b=(s1[0]==s2[0]&&s1[1]==s2[1])&&a;
    int c=!(s1[2]<='C'^s2[2]<='C')&&b;
    int x=int(s2[2])-int(s1[2]);
    int d=(abs(x)==1)&&c;
    cout<<a<<b<<c<<d;
    return 0;
}
