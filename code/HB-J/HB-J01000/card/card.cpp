#include<bits/stdc++.h>
using namespace std;
int sum[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int a[500005];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=0;
    }
    vector<int>s;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(!s.empty()){
                if(s.back()==a[j]){
                    s.pop_back();
                }
            }
            s.push_back(a[j]);
        }
        while(!s.empty()){
            int q=s.back();
            sum[q]++;
            s.pop_back();
        }
        s.clear();
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}
