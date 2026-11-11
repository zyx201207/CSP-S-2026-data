#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(false);
    string t1,z1,t2,z2;
    cin>>t1>>z1>>t2>>z2;
    if(t1==t2) cout<<'1';
    else cout<<'0';
    if(t1==t2&&z1[1]==z2[1]&&z1[0]==z2[0]) cout<<'1';
    else cout<<'0';
    if(t1==t2&&z1[1]==z2[1]&&z1[0]==z2[0]&&(('A'<=z1[2]&&z1[2]<='C'&&'A'<=z2[2]&&z2[2]<='C')||('D'<=z1[2]&&z1[2]<='F'&&'D'<=z2[2]&&z2[2]<='F'))) cout<<'1';
    else cout<<'0';
    if(t1==t2&&z1[1]==z2[1]&&z1[0]==z2[0]&&(('A'<=z1[2]&&z1[2]<='C'&&'A'<=z2[2]&&z2[2]<='C'&&abs(z1[2]-z2[2])==1)||('D'<=z1[2]&&z1[2]<='F'&&'D'<=z2[2]&&z2[2]<='F'))) cout<<'1';
    else cout<<'0';
    cout<<'\n';
    return 0;
}