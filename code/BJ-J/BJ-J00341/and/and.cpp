#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[20005];
long long memo[200005];
//struct node
//{
  //  long long color;
   // long long cost;
//};
vector<pair<long long,long long>> v;
int main(){
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
       // cout<<a[i];
        v.push_back({0,0});
        int l=v.size();
        for(int j=0;j<l;j++){
            long long color=v[j].first;
            long long cost=v[j].second;
            if(color>=m) continue;
            long long ncost=cost&a[i];
            if(color==0) ncost=a[i];
            memo[color+1]=max(memo[color+1],ncost);
            v.push_back({color+1,ncost});
            //cout<<a[i]<<' '<<color<<' '<<cost<<' '<<ncost<<endl;
        }
    }
    cout<<memo[m];

    return 0;
}
