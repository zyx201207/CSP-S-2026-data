#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int ch1,h1,ch2,h2;
char l1,l2;
bool x=0;
bool q(char c){
    if(c=='A'||c=='B'||c=='C')return 1;
    else return 0;
}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>c1>>c2>>c3>>c4;
    for(int i=0;i<c1.size();i++)ch1=ch1*10+c1[i]-'0';
    for(int i=0;i<c3.size();i++)ch2=ch2*10+c3[i]-'0';
    h1=(c2[0]-'0')*10+c2[1]-'0';
    h2=(c4[0]-'0')*10+c4[1]-'0';
    l1=c2[2],l2=c4[2];
    if(int(l1)==int(l2)+1||int(l1)==int(l2)-1)x=1;
    cout<<(ch1==ch2)<<((ch1==ch2)&&(h1==h2))<<((ch1==ch2)&&(h1==h2)&&(q(l1)==q(l2)))<<((ch1==ch2)&&(h1==h2)&&(q(l1)==q(l2))&&x)<<'\n';
    return 0;
}
