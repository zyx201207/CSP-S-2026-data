#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn=500005;
ll m,n;
vector<int> a,b;
int res[maxn];
bool dist[maxn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        int te;
        cin>>te;
        b.push_back(te);
    }
    int res=0,re=0;
    for(int k=0;k<n;++k){
        res=max(re,res);
        re=0;
        a=b;
        sort(a.begin(),a.end());
        fill(dist,dist+n+5,false);
        ll cnt=m;

        for(int i=k;i>=0;--i){
            if(cnt<0)
               break;
                int temp=a[k]-a[i];
                if(cnt>=temp){
                    cnt-=temp;
                    a[i]+=temp;
                }
        }
        for(int i=n-1;i>=0;--i){
           if(!dist[i]&&a[i]==a[k]){
              re++;
              dist[i]=true;
           }
        }
    }

    cout<<res;
    return 0;
}
