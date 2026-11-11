#include<bits/stdc++.h>
//#define int long long
using namespace std;
//#define pii pair<int,int>
#define endl '\n'
void solve(){
    string s1,s2,c1,c2;
    cin>>c1>>s1>>c2>>s2;
    if(s1[2]=='F')s1[2]='E';
    if(s2[2]=='F')s2[2]='E';
    if(c1==c2){
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1]){
            cout<<1;
            if((s1[2]<'D'&&s2[2]<'D')||(s1[2]>='D'&&s2[2]>='D')){
                cout<<1;
                if(abs(s1[2]-s2[2])==1){
                    cout<<1;
                }
                else cout<<0;
            }
            else cout<<0<<0;
        }
        else{
            cout<<0<<0<<0;
        }
    }
    else{
        cout<<0<<0<<0<<0;
    }

}
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    //freopen("travel3.in","r",stdin);
    //freopen("travel.out","w",stdout);
    int t=1;
    //cin>>t;
    while(t--)solve();
}/*

感觉很简单但是放不下心怎么办
别卡我谢谢喵
下午csps我会拥有一个雷霆大1.5L水壶加上三个500mL的冰红茶全都装满水
运气好的话还会再有一个2.1L的雷霆大水壶我就会拥有5.1L的雷霆储水量
运气坏就是4.5L
再坏就只有3L了😢
*/
