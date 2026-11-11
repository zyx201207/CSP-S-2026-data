#include<iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1,c2,s2;
    char a,b;
    cin>>c1>>s1>>a>>c2>>s2>>b;
    //cout<<c1<<" "<<s1<<" "<<a<<" "<<c2<<" "<<s2<<" "<<b;
    bool f1=(c1==c2),f2=((s1==s2)&&f1);
    cout<<f1;
    cout<<f2;
    bool f3=0;
    if(a-'A'<=2&&b-'A'<=2) f3=1;
    else if(a-'A'>2&&b-'B'>2) f3=1;
    cout<<(f3&&f1&&f2);
    if(abs(a-b)==1&&f3&&f2&&f1) cout<<1;
    else cout<<0;
    return 0;
}
