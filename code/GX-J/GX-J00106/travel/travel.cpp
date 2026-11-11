#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long a1[10005],b1[10005],a2[10005],b2[10005];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<'1';
    else cout<<'0';
    int x=1;
    for(int i=0;i<=1;i++){
        if(s1[i]!=s2[i]){
            x=0;
            break;
        }
    }
    if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')) cout<<'1';
    else cout<<'0';
    if(x==1) cout<<'1';
    else cout<<'0';
    if(s1[2]-1==s2[2]||s1[2]+1==s2[2]) cout<<'1';
    else cout<<'0';
    return 0;
}
