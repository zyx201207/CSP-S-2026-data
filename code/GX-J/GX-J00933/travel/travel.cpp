#include<bits/stdc++.h>
using namespace std;
string a,aa,b,bb;
int g;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>aa>>b>>bb;
    if(a==b){cout<<1;g++;}
    else cout<<0;

    if(aa[0]==bb[0]&&aa[1]==bb[1]&&g==1){cout<<1;g++;}
    else cout<<0;

    if( ( (aa[2]<='C'&&bb[2]<='C') || (aa[2]>='D'&&bb[2]>='D') ) &&g==2){cout<<1;g++;}
    else cout<<0;

    if(g==3&&abs(aa[2]-bb[2])==1)cout<<1;
    else cout<<0;
    return 0;
}

