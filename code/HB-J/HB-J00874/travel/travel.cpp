#include<bits/stdc++.h>
using namespace std;
int main(){
    int c1=0,c2=0;
    string s1=0,s2=0;
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2;
    cin>>s1>>s2;
    if(c1==c2) cout<<"1";
    if(s1[0]==s2[0] && s1[1]==s2[1])
    if((int)s1[2]-(int)s2[2]==1 || (int)s2[2]-(int)s1[2]==1) cout<<"1";
    return 0;
}
