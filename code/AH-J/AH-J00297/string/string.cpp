#include<bits/stdc++.h>
using namespace std;
int n;
int t,cnt;
string s,q;
char k;
void hw(){
    for(int i=0;i<s.size();i++){
        if(s[i]!=q[i]){
            cnt++;
        }
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        cin>>k;
        for(int j=1;j<=t;j++){
            s+=k;
        }
    }
    for(int i=s.size()-1;i>=0;i--){
        char x=s[i];
        q+=x;
    }
    hw();
    cout<<cnt/2;
    return 0;
}




