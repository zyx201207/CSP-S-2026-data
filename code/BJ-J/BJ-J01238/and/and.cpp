#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
map<int,vector<int> > mp;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int maxx=-1;
    for(int i=1;i<=n;i++) {
        int x1;
        int x;
        cin>>x;
        x1=x;
        maxx=max(maxx,x);
        long long pow=1;
        while(x){
            if(x%2==1) mp[pow].push_back(x1);
            x/=2;
            pow*=2;
        }
    }
    if(m==1){
        cout<<maxx;
        return 0;
    }
    /*(int i=1;i<=n;i++){
        for(auto e:a[i]){
            cout<<e.first<<" "<<e.second<<" "<<endl;
        }
        cout<<endl<<endl;
    }*/
    int ans=0;
    for(long long pw=1;pw<=1<<30;pw*=2){
        if(mp[pw].empty()||mp[pw].size()<m) continue;
        sort(mp[pw].begin(),mp[pw].end(),cmp);
        //for(int e:mp[pw]) cout<<e<<" ";
        //cout<<endl;
        int sum=mp[pw][0];
        for(int i=0;i<m;i++) sum=sum&mp[pw][i];
        ans=max(ans,sum);
    }
    cout<<ans;
    return 0;
}
