#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans,cnt[30],nd[30];
multiset<int>st;
vector<int>v;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=0;j<30;j++){
            if(a[i]&(1<<j)){
                cnt[j]++;
            }
        }
    }
    for(int i=29;i>=0;i--){
        if(cnt[i]>=m){
            ans+=(1<<i);
            for(int j=1;j<=n;j++){
                if(a[j]&(1<<i)){
                    for(int k=0;k<i;k++){
                        if(a[j]&(1<<k)){
                            nd[k]++;
                        }
                    }
                    st.insert(a[j]);
                }
            }
            while(i>=0){
                if(nd[i]>=m){
                    ans+=(1<<i);
                    v.clear();
                    for(auto j:st){
                        if(j&(1<<i)){
                            continue;
                        }
                        for(int k=0;k<i;k++){
                            if(j&(1<<k)){
                                nd[k]--;
                            }
                        }
                        v.push_back(j);
                    }
                    for(auto j:v){
                        st.erase(j);
                    }
                }
                i--;
                //cout<<i<<'\n';
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
