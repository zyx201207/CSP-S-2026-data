#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[600001],ans[600001];
vector<int> t;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdin);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        while(t.size()>0)t.pop_back();
        for(int j=i;j<=n;j++){
            for(int k=0;k<t.size();k++){
                if(t[k]==a[j]){
                    while(t.size()!=k+1)t.pop_back();
                    t.pop_back();
                    break;
                }
            }
            t.push_back(a[j]);
        }
        for(int j=0;j<t.size();j++){
            ans[t[j]]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
