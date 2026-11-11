#include<bits/stdc++.h>

using namespace std;
#define ll long long
const int maxn=2e5+10;
int n;
vector<pair<ll,char> > x;
ll ans,num=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        int aaa;
        char bbb;
        cin>>aaa>>bbb;
        num+=aaa;
        if(i!=0 && bbb==x.back().second){
            x.back().first+=aaa;
        }else x.push_back({aaa,bbb});
    }
    ll ncnt=0;
    int j=x.size()-1;
    for(int i=0;i<x.size();i++){
        if(ncnt>=num/2)break;
        char c=x[i].second;
        ll sn=(ncnt+x[i].first>num/2 ? (num/2-ncnt) : x[i].first);
        while(sn){
            if(x[j].second==c){
                if(x[j].first>=sn){
                    x[j].first-=sn;
                    sn=0;
                }else{
                    sn-=x[j].first;
                    j--;
                }
            }else{
                if(x[j].first>=sn){
                    x[j].first-=sn;
                    ans+=sn;
                    sn=0;
                }else{
                    ans+=x[j].first;
                    sn-=x[j].first;
                    j--;
                }
            }
        }
        ncnt+=x[i].first;
    }
    cout<<ans<<'\n';
    return 0;
}
