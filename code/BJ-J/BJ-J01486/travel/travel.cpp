#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int maxn=2e5+10;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
bool mp[6]={1,1,1,0,0,0};
int h[6]={1,2,3,4,0,5};
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(s1[0]==s2[0] && s1[1]==s2[1]){
            cout<<"1";
            if(mp[s1[2]-'A']==mp[s2[2]-'A']){
                cout<<"1";
                if(abs(h[s1[2]-'A']-h[s2[2]-'A'])<=1){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    cout<<endl;
    return 0;
}
//100+100+100+4*4=316?
