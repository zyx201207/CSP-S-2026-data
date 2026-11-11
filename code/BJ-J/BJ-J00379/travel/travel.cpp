#include <bits/stdc++.h>
using namespace std;
int a1,b1,c3,d3;
string a,b,c,d;
char c1,c2;
bool isnum(char c){
    return '0'<=c&&c<='9';
}
int getnum(string str){
    int ans=0;
    for (int i=0;i<2;i++)
        ans=ans*10+(str[i]-'0');
    return ans;
}
bool yice(char c1,char c2){
    return (c1<='C'&&c2<='C')||(c1>='D'&&c2>='D');
}
bool xianglin(char c1,char c2){
    return abs(int(c1)-int(c2))==1;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    //cout << a << " " << b << " " << c << " " << d << '\n';
    c1=b[2],c2=d[2];
    a1=getnum(a);
    b1=getnum(b);
    c3=getnum(c);
    d3=getnum(d);
    //cout << c1 << " " << c2 << '\n';
    //cout << a1 << " " << b1 << " " << c3 << " " << d3 << '\n';
    if (a1!=c3){
        cout << "0000\n";
        return 0;
    }
    else if (b1!=d3){
        cout << "1000\n";
        return 0;
    }
    else if (!yice(c1,c2)){
        cout << "1100\n";
        return 0;
    }
    else if (!xianglin(c1,c2)){
        cout << "1110\n";
        return 0;
    }
    cout << "1111\n";
    return 0;
}
