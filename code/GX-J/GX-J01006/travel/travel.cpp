#include<bits/stdc++.h>
using namespace std;
string a,sa,b,sb,n,m;
long long x=0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>sa>>b>>sb;
    n=sa[0]+sa[1];
    m=b[0]+sb[1];
    if(a==b) cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    if(n==m) cout<<1;
    else cout<<0;
    if(n==m&&((sa[2]<='C'&&sb[2]<='C')||(sa[2]>='D'&&sb[2]>='D')))
       {
           cout<<1;
           x++;
       }
    else cout<<0;
    if(x!=0&&(char(sa[2]+1)==sb[2]||char(sa[2]-1)==sb[2])) cout<<1;
        else cout<<0;
    return 0;
}
