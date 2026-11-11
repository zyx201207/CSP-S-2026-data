#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char q,p;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>q>>c>>d>>p;
    if(a==c)cout<<1;
    else cout<<0;
    if(b==d&&a==c)cout<<1;
    else cout<<0;
    if(((q<='C'&&p<='C')||(q>='D'&&p>='D'))&&b==d&&a==c)cout<<1;
    else cout<<0;
    if((q==p-1||q==p+1||(q=='D'&&p=='F')||(q=='F'&&p=='D'))&&((q<='C'&&p<='C')||(q>='D'&&p>='D'))&&b==d&&a==c)cout<<1;
    else cout<<0;
    return 0;
}
