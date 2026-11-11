#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    bool lx=true;
    for(int i=1;i<n;i++)
        if(a[i-1]>a[i]){
            lx=false;
            break;
        }
    vector<int> ans(m+1);
    for(int i=1;i<=n;i++){
        vector<int> c;
        for(int j=i-1;j<n;j++){
            if(lx){
                if(!c.empty()){
                    if(c.back()!=a[j])
                        c.push_back(a[j]);
                }
                else
                    c.push_back(a[j]);
            }else{
                bool flag=false;
                for(int k=0;k<c.size();k++){
                    if(c[k]==a[j])
                        flag=true;
                }
                if(flag){
                    while(c.back()!=a[j])
                        c.pop_back();
                }
                else{
                    c.push_back(a[j]);
                }
            }
        }
        vector<bool> x(m+1);
        for(int j=0;j<c.size();j++){
            if(c[j]<=m){
                x[c[j]]=1;
            }
        }
        for(int i=1;i<=m;i++)
            ans[i]+=x[i];
    }
    for(int i=1;i<=m;i++)
        cout<<ans[i]<<' ';
    return 0;
}
