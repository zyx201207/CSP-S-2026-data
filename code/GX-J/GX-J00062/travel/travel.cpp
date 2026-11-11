#include <bits/stdc++.h>
using namespace std;

int a,b;
string a1,b1;
int ans[10];
int al=0,bl=0,as=0,bs=0;

int main(){
    memset(ans,0,sizeof(ans));
    ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>a1>>b>>b1;
    al=(a1[0]-'0')*10+a1[1]-'0';
    bl=(b1[0]-'0')*10+b1[1]-'0';
    as=a1[2]-'A';
    bs=b1[2]-'A';
    if(bs==5)bs-=1;
    if(as==5)as-=1;
    cout<<al<<' '<<bl<<'\n';
    ans[0]=((a==b)?1:0);
    ans[1]=((ans[0]==1&&al==bl)?1:0);
    ans[2]=((ans[1]==1&&((as<=2&&bs<=2)||(as>=3&&bs>=3)))?1:0);
    if(bs<as)swap(bs,as);
    ans[3]=((ans[1]==1&&(bs-as==1)&&(bs!=3))?1:0);
    cout<<ans[0]<<ans[1]<<ans[2]<<ans[3];
    return 0;
}

// standard method: fast read
// the difficulty: read
// 09:05(15min)
