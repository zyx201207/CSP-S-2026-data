#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n;
    int m;
    cin>>n>>m;
    map<int,long long>mp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    string s="";
    for(int j=1;j<=n;j++){
        for(int i=j;i<=n;i++){
            if(s.find(a[i])!=-1){
                for(int i=s.find(a[i]);i<s.size();i++)
                    s.erase(i);
            }
            s+=(a[i]+'0');
        }3
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        s="";
    }
    for(int i=0;i<mp.size();i++){
        cout<<mp[i]<<" ";
    }
    return 0;
}
