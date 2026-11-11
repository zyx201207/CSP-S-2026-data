#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
vector <int> sum;
vector <int> input;

bool check(int a,int b){
    int s=input[b]*(b-a)-(sum[b-1]-sum[a-1]);
    return s<=m;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;

    input.resize(n+1);
    sum.resize(n+1);

    for(int i=1;i<=n;i++) cin>>input[i];
    sort(input.begin()+1,input.end());
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+input[i];

    int ans=0;
    for(int i=2;i<=n;i++){
        int l=1,r=i-1;
        while(l<=r){
            int m=(l+r)>>1;
            if(check(m,i)){
                ans=max(ans,i-m+1);
                r=m-1;
            }
            else
                l=m+1;
        }
    }

    cout<<ans;
    
    return 0;
}