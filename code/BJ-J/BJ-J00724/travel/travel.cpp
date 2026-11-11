#include<bits/stdc++.h>
using namespace std;
using ll =long long;
ll c1,s1;
string c2,s2,ans;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c1>>c2>>s1>>s2;
    if(c1==s1){
        ans+="1";
    }
    else{
        ans+="0000";
        cout<<ans;
        return 0;
    }
    if(c2[0]+c2[1]==s2[0]+s2[1]){
        ans+="1";
    }
    else{
        ans+="000";
        cout<<ans;
        return 0;
    }
    if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'){
        if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
            ans+="1";
            if(c2[2]=='A'&&s2[2]=='B'){
                ans+="1";
            }
            else if(c2[2]=='B'&&s2[2]=='C'){
                ans+="1";
            }
            else if(s2[2]=='A'&&c2[2]=='B'){
                ans+="1";
            }
            else if(s2[2]=='B'&&c2[2]=='C'){
                ans+="1";
            }
            else{
                ans+="0";
                cout<<ans;
                return 0;
            }
        }
        else{
            ans+="00";
            cout<<ans;
            return 0;
        }

    }
    else if(c2[2]=='D'||c2[2]=='F'){
        if(s2[2]=='D'||s2[2]=='F'){
            ans+="11";
        }
        else{
            ans+="00";
        }
    }
    cout<<ans;
    return 0;
}
