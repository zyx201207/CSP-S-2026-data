#include<bits/stdc++.h>
using namespace std;
int s[200005];
string st[200005];
int n,m;
int mx=0;
vector<int> ve(50);
vector<string> ve1;
int ans=0;
void solve(){
    // for(int i=0;i<ve1[0].size();i++){
    //     cout<<ve[i];
    // }
    // cout<<'\n';
    // for(int i=0;i<ve1.size();i++){
    //     cout<<ve1[i]<<'\n';
    // }
    int ki=0;
    while(ve[ki]<m){
        ki++;
        if(ki>ve.size()) return ;
    }
    vector<int> nve(ve.size());
    // vector<string> nve1;
    for(int i=0;i<ve.size();i++){
        ve[i]=0;
    }
    bool con=0;
    for(int i=0;i<ve1.size();i++){
        if(ve1[i][ki]=='1'){
            ve1[i][ki]='0';
            //nve1.push_back(ve1[i],1);
        }
        else{
            for(int j=0;j<ve1[i].size();j++){
               ve1[i][j]='0';
            }
        }
         for(int j=0;j<ve1[i].size();j++){
             ve[j]+=(ve1[i][j]-'0');
             if(ve[j]>=m) con=1;
         }
    }
    // ve=nve;
    // //ve1=nve1;
    // for(int i=0;i<ve1[0].size();i++){
    //     cout<<ve[i];
    // }
    // cout<<'\n';
    // for(int i=0;i<ve1.size();i++){
    //     cout<<ve1[i]<<'\n';
    // }
    ans+=(1<<(ve1[0].size()-ki-1));
    if(con)
     solve();
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=n;i++){
        while(s[i]){
            st[i]= (char)('0'+s[i]%2) +st[i];
            s[i]/=2;
        }
        mx=max(mx,(int)st[i].size());
    }
    for(int i=1;i<=n;i++){
        int siz=st[i].size();
        for(int j=1;j<=(mx-siz);j++){
            st[i]='0'+st[i];
        }
        for(int j=0;j<st[i].size();j++){
            ve[j]+=(st[i][j]-'0');
        }
        ve1.push_back(st[i]);
    }
    solve();
    cout<<ans;
    return 0;
}
