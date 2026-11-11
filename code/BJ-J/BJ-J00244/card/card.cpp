#define int long long
#include<bits/stdc++.h>
using namespace std;
int n,m,ans[300001];
vector<int> t;
vector<int> a;
int ck(int l){
    for(int i=0;i<t.size();i++){
        if(l==t[i]){
            return i;
        }
    }
    return -1;
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int b;
        cin>>b;
        a.push_back(b);
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int tmp=ck(a[j]);
            if(tmp==-1){
                t.push_back(a[j]);
            }
            else{
                for(int i=tmp;i<t.size();i++){
                    t.pop_back();
                }
            }
        }
        for(int i=0;i<t.size();i++){
            ans[t[i]]++;
        }
        t.clear();
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}

