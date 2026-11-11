#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char z1,z2;
    int c1,c2,n,m;
    cin>>c1>>n>>z1;
    cin>>c2>>m>>z2;
    cout<<(c1==c2);
    cout<<((c1==c2)&&(n==m));
    bool g1=0,g2=0;//在D侧
    if(z1<='C'){
        g1=1;
    }
    if(z2<='C'){
        g2=1;
    }
    int s=abs(z1-z2);

    cout<<((c1==c2)&&(n==m)&&(g1==g2));
    cout<<((c1==c2)&&(n==m)&&(g1==g2)&&(s==1));
    return 0;
}












