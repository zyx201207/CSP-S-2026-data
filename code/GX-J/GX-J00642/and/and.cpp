#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans=0;
    vector<int> a,b;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a.push_back(t);
    }
    for(int i=0;i<m;i++){
        auto t=*max_element(a.begin(),a.end());
        for(int j=0;j<a.size();j++){
            if(a[j]==t){
                b.push_back(a[j]);
                a.erase(a.begin()+j,a.begin()+j+1);
            }
        }
    }
    ans=b[0];
    for(int i=1;i<b.size();i++){
        ans=ans&b[i];
    }
    cout<<ans;
    return 0;
}
