#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,e =0;//left num
    char l,m,n,p=0;//right letter
    cin>>a;
    cin>>b>>l;
    cin>>c>>m;
    cin>>d>>n;
    cin>>e>>p;
    char S =b*l+c*m+d*n+e*p;
    char S[a*2]=d;
    char S[a*2-1]=c;
    cout<< S[a];
    return 0;
}
