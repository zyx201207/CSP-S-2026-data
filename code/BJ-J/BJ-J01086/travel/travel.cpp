#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

bool g(string a,string b){
    return (c1==c2)&&(a[0]==b[0]&&a[1]==b[1]);
}

bool f(string a){
    return a[2]<='C'&&a[2]>='A';
}

bool f1(string a,string b){
    return g(a,b)&&(!(f(a)^f(b)));
}

bool f2(string a,string b){
    return (abs(a[2]-b[2])==1)&&f1(a,b);
}

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    cout<<(c1==c2)<<g(s1,s2)<<f1(s1,s2)<<f2(s1,s2)<<'\n';
    return 0;
}