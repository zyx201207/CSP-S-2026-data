#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);    
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    a1=' '+a1;
    a2=' '+a2;
    b1=' '+b1;
    b2=' '+b2;
    int a4,b4;
    if(a2[3]<='C') a4=1;
    else a4=0;
    if(b2[3]<='C') b4=1;
    else b4=0;
    int ans1=0,ans2=0,ans3=0,ans4=0;
    if(a1==b1) ans1=1;
    if(a1==b1 && a2[1]==b2[1] && a2[2]==b2[2]) ans2=1;
    if(ans2 && a4==b4)  ans3=1;
    if(ans3 && abs(a2[3]-b2[3])==1) ans4=1;
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
