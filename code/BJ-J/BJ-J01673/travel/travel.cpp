#include<bits/stdc++.h>
#define N 1000050
#define ll long long
#define qck ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n,m;
string n1,m1,n2,m2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    qck;
    cin>>n>>n1>>m>>m1;
    n2=n1[0]+n1[1];
    m2=m1[0]+m1[1];
    bool onway1=n1[2]>='A'&&n1[2]<='C'&&m1[2]>='A'&&m1[2]<='C'&&n==m&&n2==m2;
    bool onway2=n1[2]>='D'&&n1[2]<='F'&&m1[2]>='D'&&m1[2]<='F'&&n==m&&n2==m2;
    bool onnext=onway2||(onway1&&!(n1[2]=='A'&&m1[2]=='C')&&!(n1[2]=='C'&&m1[2]=='A'));
    cout<<(n==m)<<((n2==m2)&&(n==m))<<(onway1||onway2)<<onnext<<"\n";
    return 0;
}