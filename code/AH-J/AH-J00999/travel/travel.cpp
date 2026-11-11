#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else cout<<0;
    int cnt1=0;
    for(int i=0;i<2;i++)
        if(s1[i]==s2[i])cnt1++;
    if(c1==c2&&cnt1==2)cout<<1;
    else cout<<0;
    char ch1;
    char ch2;
    for(int i=0;i<=2;i++){
        ch1=s1[i];
        ch2=s2[i];
    }
    if(c1==c2&&ch1<='C'&&ch2<='C'&&cnt1==2)cout<<1;
    else cout<<0;
    if(c1==c2&&s1[2]<='C'&&s2[2]<='C'&&cnt1==2&&abs((ch1-'0')-(ch2-'0'))==1)
        cout<<1;
    else
        cout<<0;
    return 0;
}
