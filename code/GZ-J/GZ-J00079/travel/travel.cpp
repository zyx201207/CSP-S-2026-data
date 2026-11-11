//GZ-J00079 贵阳市新世界学校 李冠儒
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void zf(){
    string c1,c2,s1,s2;
    cin>>c1>>s1>>c2>>s2;

    if(c1==c2){
        cout<<1;
        string str1=s1.substr(0,s1.size()-1);
        string str2=s2.substr(0,s2.size()-1);
        if(str1==str2){
            cout<<1;
            ll cnt1=0,cnt2=0;
            for(char i='A';i<='C';i++){
                if(s1[s1.size()-1]==i)cnt1=1;
                if(s2[s2.size()-1]==i)cnt2=1;
            }
            for(char i='D';i<='F';i++){
                if(s1[s1.size()-1]==i)cnt1=2;
                if(s2[s2.size()-1]==i)cnt2=2;
            }
            if(cnt1==cnt2){
                cout<<1;
                if(s1[s1.size()-1]+1==s2[s2.size()-1]||s1[s1.size()-1]==s2[s2.size()-1]+1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<0;cout<<0;
            }
        }else{
            cout<<0;cout<<0;cout<<0;
        }
    }else{
        cout<<0;cout<<0;cout<<0;cout<<0;
    }
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();cout.tie();
    int t=1;
    //cin>>t;
    while(t--)zf();
    return 0;
}
