#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
vector<int> p;
vector<vector<int> > pd(M);
int ans[M];
int main(){
    //freopen("card1.in","r",stdin);
    //freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        p.push_back(x);
        pd[p[i]].push_back(i);
    }
    for(int i=n;i>=1;i--){
        for(int j=n-i;j<n;j++){
            ans[p[i]]++;
            auto it=pd[p[i]].end();
            it--;
            j=*it;
        }
    }
    for(int i=0;i<m;i++)cout<<ans[i];
    return 0;
}
