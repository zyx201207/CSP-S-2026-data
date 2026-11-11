#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll a[200005];
ll ans;
map<string,ll> mp;
void dfs(ll cur,ll num,string s){
    if(num>m){
        ans=max(ans,cur);
        return;
    }
    if(mp.find(s)!=mp.end()){
        if(cur<=mp[s]) return;
    }else{
        mp[s]=cur;
    }
    for(int i=n;i>=1;i--){
        if(s[i]=='1') continue;
        s[i]='1';
        dfs(cur&a[i],num+1,s);
        s[i]='0';
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    string s;
    for(int i=0;i<=n;i++){
        s+='0';
    }
    for(int i=n;i>=1;i--){
        s[i]='1';
        dfs(a[i],2,s);
        s[i]='0';
    }
    cout<<ans;
    return 0;
}

/*#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
string a[200005];
bool cmp(string x,string y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x==0){
            a[i]="0";
            continue;
        }
        while(x>0){
            a[i]+=to_string(x%2);
            x/=2;
        }
        for(int j=0,q=a[i].length()-1;j<q;j++,q--){
            swap(a[i][j],a[i][q]);
        }
    }
    sort(a+1,a+1+n,cmp);
    string s=a[m];
    ll ans=0;
    ll cur=1;
    for(int i=s.length()-1;i>=0;i--){
        ans+=cur*(s[i]-'0');
        cur*=2;
    }
    cout<<ans;
    return 0;
}*/
