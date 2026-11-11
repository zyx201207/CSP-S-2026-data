#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c11,c22,s11,s22,a,b;
    char s,s2;
    cin>>c11>>s11>>s>>c22>>s22>>s2;
    a=s,b=s2;
    if(c11!=c22){
        cout<<"0000";
        return 0;
    }
    else cout<<1;
    if(c11==c22&&s11==s22) cout<<1;
    else cout<<0;
    if(c11==c22&&s11==s22&&(a-b<=2||b-a<=2)&&a+b!=135&&((a!=66&&b!=68)||(a!=68&&b!=66))) cout<<1;
    else cout<<0;
    if(s11==s22&&(a-b==1||b-a==1)&&(a+b!=135)) cout<<1;
    else cout<<0;
    return 0;
}
