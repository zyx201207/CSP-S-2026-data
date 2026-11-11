#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long cnt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    //02 01A 02 01B
    cin>>c1>>s1>>c2>>s2;
    //cout<<lc1;
    cnt=0;
    for(int i=0;i<=1;i++){
        if(c1[i]==c2[i]){
            cnt++;
        }
    }
    if(cnt==2){
        cout<<1;
        cnt=0;
        for(int i=0;i<=1;i++){
            if(s1[i]==s2[i]){
                cnt++;
            }
        }
        if(cnt==2){
            cout<<1;
            if((s1[2]=='A')&&((s2[2]=='B')||(s2[2]=='C'))){
                cout<<1;
                if(s2[2]=='B'){
                    cout<<1;
                }
                else cout<<0;
            }
            else if((s1[2]=='B')&&((s2[2]=='A')||(s2[2]=='C'))){
                cout<<1<<1;
            }
            else if((s1[2]=='C')&&((s2[2]=='B')||(s2[2]=='A'))){
                cout<<1;
                if(s2[2]=='B'){
                    cout<<1;
                }
                else cout<<0;
            }
            else if((s1[2]=='D')&&(s2[2]=='F')){
                cout<<1<<1;
            }
            else if((s1[2]=='F')&&(s2[2]=='D')){
                cout<<1<<1;
            }
            else cout<<0<<0;
        }
        else cout<<0<<0<<0;
    }
    else cout<<0<<0<<0<<0;
    return 0;
}
