#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans;
vector<int>mp[32];
int ii,n,m;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int x=a[i];
        string s;
        while(x){
            s+=x%2;
            x/=2;
        }
        for(int j=0;j<s.size();j++){
            if(s[j])mp[j].push_back(i);
        }
    }
    for(int i=30;i>=0;i--){
        if(mp[i].size()>=m&&ans==0)ii=i,ans+=pow(2,i);
        else{
            if(mp[i].size()>=m){
                int f=0;
                for(int i:mp[i]){
                    int d=find(mp[ii].begin(),mp[ii].end(),i)-mp[ii].begin();
                    if(d!=mp[ii].size())f++;
                }
                if(f>=m)ans+=pow(2,i);
            }
        }
    }
    cout<<ans;
    return 0;
}
/*
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans;
vector<int>mp[32];
int ii,n,m;
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int x=a[i];
        string s;
        while(x){
            s+=x%2;
            x/=2;
        }
        for(int j=0;j<s.size();j++){
            if(s[j])mp[j].push_back(a[i]);
        }
    }
    for(int i=30;i>=0;i--){
        if(mp[i].size()>=m&&ans==0){
            ii=i;
            ans+=pow(2,i);
            // vector<pair<int,int>>p;
            // for(int j=0;j<mp[i].size();j++){
            //     int x=mp[i][j],r=0;
            //     while(x){
            //         r+=x%2;
            //         x/=2;
            //     }
            //     p.push_back({r,mp[i][j]});
            // }
            // sort(p.begin(),p.end(),greater<pair<int,int>>());
            // for(int j=m;j<p.size();j++)mp[i].pop_back();
        }else{
            if(mp[i].size()>=m){
                int f=0;
                for(int j:mp[i]){
                    int d=find(mp[ii].begin(),mp[ii].end(),j)-mp[ii].begin();
                    if(d!=mp[ii].size())f++;
                }
                if(f==m)ans+=pow(2,i);
            }
        }
    }
    cout<<ans;
    return 0;
}
*/