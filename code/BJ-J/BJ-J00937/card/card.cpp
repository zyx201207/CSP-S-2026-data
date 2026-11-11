#include<iostream>
#include<cstring>
#include<unordered_set>
using namespace std;
int a[500005],ans[300005],cnt=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    bool flag=true;
    cin>> n >> m;
    for(int i=1;i<=n;i++){
        cin>> a[i];
        if(a[i]<a[i-1]) flag=false;
    }
    if(flag){
        for(int i=1;i<=n;i++) ans[a[i]]=i;
        for(int i=1;i<=m;i++) cout<< ans[i] << " ";
        return 0;
    }
    for(int e=1;e<=n;e++){
        int tmpl=e;
        cnt=0;
        unordered_multiset<int> ms;
        for(int i=e;i<=n;i++){
            ms.insert(a[i]);
            if(ms.count(a[i])==2){
                while(ms.count(a[i])){
                    ms.erase(ms.begin());
                }
                ms.insert(a[i]);
            }
        }
        for(auto i:ms){
            ans[i]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<< ans[i] << " ";
    }
    return 0;
}
