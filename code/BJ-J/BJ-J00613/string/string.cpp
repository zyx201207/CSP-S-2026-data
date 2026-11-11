#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s={};
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        char c;
        cin>>c;
        for(int i=1;i<=x;i++){
            s+=c;
        }
    }
    int len=s.size();
    int cnt=0;
    for(int i=0;i<(len+1)/2;i++){
        if(s[i]!=s[len-i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}