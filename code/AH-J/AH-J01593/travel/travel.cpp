#include<bits/stdc++.h>
using namespace std;

string ta,sa,tb,sb;
bool a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>ta>>sa>>tb>>sb;
    if(ta==tb) a=1;
    if(a==1 && sa.substr(0,2)==sb.substr(0,2)) b=1;
    if(b==1 && ( ( sa[2]<='C' && sb[2]<='C') || ( sa[2]>='D' && sa[2]>='D' ) ) ) c=1;
    if(c==1 && ( abs(sa[2]-sb[2])==1 || ( sa[2]=='F' && sb[2]=='D' ) || ( sa[2]=='D' && sb[2]=='F' ) ) ) d=1;
    cout<<a<<b<<c<<d;
    return 0;
}
