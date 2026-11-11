#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
vector<pair<int,char> > s;
int a;
char c;
ll cnt=0;
void solve(){
    cin>>n;
    while(n--){
        cin>>a>>c;
        s.push_back({a,c});
    }
    int i=0,j=s.size()-1;
    while(i<=j){
        //cout<<i<<' '<<j<<' ';
        if(s[i].second!=s[j].second){
            cnt+=min(s[i].first,s[j].first);
            if(s[i].first==s[j].first) i++,j--;
            else if(s[i].first>s[j].first){
                s[i].first-=s[j].first;
                j--;
            }
            else if(s[i].first<s[j].first){
                s[j].first-=s[i].first;
                i++;
            }
        }
        else{
            if(s[i].first==s[j].first) i++,j--;
            else{
                if(s[i].first>s[j].first){
                    s[i].first-=s[j].first;
                    j--;
                }else{
                    s[j].first-=s[i].first;
                    i++;
                }
            }
        }
        //cout<<cnt<<'\n';
    }
    cout<<cnt;
    //for(auto i:s){
    //    cout<<i.first<<' '<<i.second<<' '<<'\n';
    //}
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
