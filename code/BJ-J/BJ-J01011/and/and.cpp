#include<bits/stdc++.h>
using namespace std;
const int LOG=29,N=200000;//29 2e5
vector<int>v[LOG+10];//2e5
int a[N+10],ok[N+10];//2e9 2e5
int main(){
    // freopen("and5.in","r",stdin);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;//2e5 2e5
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=LOG;j>=0;j--)
            if((a[i]&(1<<j))!=0)
                v[j].push_back(i);
        // if(i%100==0)cout<<"!!!!!"<<i<<"!!!!!\n";
    }
    int ans=0,last=0;//2e9 2e5
    for(int i=LOG;i>=0;i--){
        vector<int>v2;//2e5
        for(int j:v[i])
            if(ok[j]==last)
                v2.push_back(j);
        // cout<<i<<' '<<v2.size()<<'\n';
        if(v2.size()<m)continue;
        last=i;
        ans+=1<<i;
        for(int j:v2)ok[j]=i;
    }
    cout<<ans;
    return 0;
}