#include<bits/stdc++.h>
#define int long long
using namespace std;
map<char,int> mp;
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int cnt=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char a1;
        cin>>x>>a1;
        for(int j=1;j<=x;j++){
            s+=a1;
        }
        mp[a1]+=x;
        cnt+=x;
    }
    if(mp.size()==1){
        cout<<0;
        return 0;
    }
    int ans=0;
    int pos;
    if(cnt&1){
        pos=(cnt+1)/2;
        cnt--;
        s.erase(pos);
    }
    else pos=cnt/2;
    int sum=0;
    for(int i=0;i<pos;i++){
        if(s[i]!=s[cnt-i])sum++;
    }
    cout<<sum;
    return 0;
}
