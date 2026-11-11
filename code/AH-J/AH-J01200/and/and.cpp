#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a[N];
vector<ll>s[33];
multiset<ll>anss;
multiset<ll>nans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ll x=a[i];
        int cnt=0;
        while(x){
            if(x&1)s[cnt].push_back(a[i]);
            x>>=1;
            cnt++;
        }
    }
    int zgw=-1;
    anss.clear();
    for(int i=31;i>=0;i--){
        if(s[i].size()>=m){
            for(auto j:s[i])anss.insert(j);
            zgw=i;
            break;
        }
    }
    for(int i=zgw;i>=0;i--){
        if(anss.size()>m){
            int cnt=0;
            for(auto j:anss)cnt+=((j>>i)&1);
            if(cnt>=m){
                nans.clear();
                for(auto j=anss.begin();j!=anss.end();j++){
                    if(((*j)>>i)&1){
                        nans.insert(*j);
                    }
                }
                anss=nans;
            }
        }else if(anss.size()==m){
            int tmp=*anss.begin();
            for(auto j:anss)tmp&=j;
            cout<<tmp;
            return 0;
        }
    }
    if(anss.empty()){
        cout<<0;
        return 0;
    }else{
        int tmp=*anss.begin();
        int cnt=1;
        for(auto j=anss.begin();j!=anss.end()&&cnt<=m;j++,cnt++){
            tmp&=(*j);
        }
        cout<<tmp;
    }
    return 0;
}
