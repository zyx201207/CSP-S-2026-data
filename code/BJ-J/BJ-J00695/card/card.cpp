#include<bits/stdc++.h>
using namespace std;
long long find(long long a,string s){
    for(long i=0;i<s.size();i++){
        if(s[i]-'0'==a){
            return i;
        }
    }
    return -1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<long long> a(n+1);
    for(long i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<long long> ans(m+1);
    for(long i=1;i<=n;i++){
            string s;
        for(long j=i;j<=n;j++){
                long long dex=find(a[j],s);
            if(dex==-1){
                s+=(a[j]+'0');
            }else{
                s.erase(dex,s.size()-dex+1);
                s+=(a[j]+'0');
            }
        }
        for(int j=0;j<s.size();j++){
            int q=s[j]-'0';
            ans[q]++;
        }

    }
    for(long i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
