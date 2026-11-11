#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt=0;
    string s;
    cin>>n;

    for(int i=1;i<=n;i++){
        string t;
        cin>>t;
        s=t+s;
    }
    string q=s;
    reverse(s[0],s[s.size()]);
    if(s==q){
        cout<<"0";
    }else{
        for(int i=1;i<=s.size();i++){
            if(s[i]!=s[i-1]){
                cnt++;
            }
        }

    }
    cout<<cnt;
    return 0;
}
