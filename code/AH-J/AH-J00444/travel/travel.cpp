#include<bits/stdc++.h>
using namespace std;
int a,b;
string A,B;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>A>>b>>B;
    if(a!=b) return cout<<"0000",0;
    if(A[0]!=B[0]||A[1]!=B[1]) return cout<<"1000",0;
    if((A[2]=='A'||A[2]=='B'||A[2]=='C')&&(B[2]=='D'||B[2]=='F')||(B[2]=='A'||B[2]=='B'||B[2]=='C')&&(A[2]=='D'||A[2]=='F')) return cout<<"1100",0;
    if(!(((A[2]-B[2]==1)||(A[2]-B[2]==-1))&&(A[2]!='C'&&B[2]!='c'))) return cout<<"1110",0;
    return cout<<"1111",0;
}
