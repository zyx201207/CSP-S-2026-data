#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[919191],cnt[91];
string bin[919191];
vector<int> v[91];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int x=a[i];
        while(x){
            bin[i]+=char('0'+x%2);
            x/=2;
        }
        for(int j=0;j<bin[i].size();j++){
            cnt[j+1]+=bin[i][j]-'0';
            if(bin[i][j]=='1'){
                v[j+1].push_back(a[i]);
            }
        }
    }
    int ans=0;
    for(int i=30;i>=1;i--){
        if(cnt[i]>=m){
            sort(v[i].begin(),v[i].end(),cmp);
            int t=INT_MAX;
            for(int j=0;j<min(m,int(v[i].size()));j++){
                t=t&v[i][j];
            }
            ans=max(ans,t);
        }
        //for(int j=0;j<v[i].size();j++){
        //    cout<<v[i][j]<<' ';
        //}
        //cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
