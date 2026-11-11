#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    int ans=0;
    while(n--){
        int x;
        cin>>x;
        char c;
        cin>>c;
        for(int i=1;i<=x;i++){
            s.push_back(c);
        }
        ans+=x;
    }
    int cnt=0;
    for(int i=0;i<ans/2;i++){
        if(s[i]!=s[ans-1-i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
