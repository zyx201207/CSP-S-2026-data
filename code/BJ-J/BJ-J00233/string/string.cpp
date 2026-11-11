#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        int a;
        char x;
        cin>>a>>x;
        for(int i=1;i<=a;i++){
            s+=x;
        }
    }
    string os=s;
    reverse(s.begin(),s.end());
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(os[i]!=s[i]){
            cnt++;
        }
    }
    cout<<cnt/2;
    return 0;
}

