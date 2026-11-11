#include<bits/stdc++.h>//rp++
using namespace std;
string n,m,n1,m1,ans;
char a='0',b='0',c='0',d='0';
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdin);
    cin>>n>>n1>>m>>m1;
    if (n==m) a='1';
    string nn,mm;
    nn[0]=n1[0];
    nn[1]=n1[1];
    mm[0]=m1[0];
    mm[1]=m1[1];
    string n2,m2;
    n2[1]=n1[2];
    m2[1]=m1[2];
    if (n==m&&nn==mm) b='1';
    if ((n==m&&nn==mm)&&(n2[1]=='A'&& m2[1]=='B' or n2[1]=='B'&&m2[1]=='A' or n2[1]=='B'&&m2[1]=='C' or n2[1]=='C'&&m2[1]=='B' or n2[1]=='F'&&m2[1]=='D' or n2[1]=='D'&&m2[1]=='F' or n2[1]=='A'&&m2[1]=='C' or n2[1]=='C'&&m2[1]=='A')) c='1';
    if ((n==m&&nn==mm)&&(n2[1]=='A'&&m2[1]=='B' or n2[1]=='B'&&m2[1]=='A' or n2[1]=='B'&&m2[1]=='C' or n2[1]=='C'&&m2[1]=='B' or n2[1]=='F'&&m2[1]=='D' or n2[1]=='D'&&m2[1]=='F')) d='1';
    cout<<a<<b<<c<<d;
    return 0;


}
