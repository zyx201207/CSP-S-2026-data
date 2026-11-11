#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll n, m, buck[35];//1 ge4 shu4
vector<ll> a, a2[35];
vector<ll> x[2];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin>>n>>m;
    a.assign(n+1, 0);
    x[0].assign(n+1, 0);
    memset(buck, 0, sizeof(buck));
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        for(int j = 31;j>=0;j--){
            buck[j] += ((a[i]>>j)&1);
        }
    }
    sort(a.begin()+1, a.end(), greater<ll>());
    for(int i = 1;i<=n;i++){
        x[0][i-1] = a[i];
    }//cout<<"111"<<endl;
    for(int i = 31;i>=0;i--){
        //cout<<i<<' '<<buck[i]<<endl;
        if(buck[i]>=m){
            // cout<<i<<endl;
            // cout<<"first"<<' ';
            // for(int j = 0;j<x[0].size();j++){
            //     cout<<x[0][j]<<' ';
            // }cout<<endl;
            //cout<<i<<' '<<x[0].size()<<' '<<x[1].size()<<endl;
            
            for(int j = 0;j<x[0].size();j++){
                if((x[0][j]>>i)&1){
                    x[1].push_back(x[0][j]);
                    // cout<<x[0][j]<<' ';
                }
                //cout<<x[0][j]<<' '<<((x[0][j]>>i)&1)<<' ';
            } //cout<<buck[i]<<' '<<i<<' ';

            // cout<<endl;
            x[0].assign(x[1].size(), 0);
            for(int j = 0;j<x[1].size();j++){
                x[0][j] = x[1][j];
            }
            // cout<<"second"<<' ';
            // for(int j = 0;j<x[1].size();j++){
            //     cout<<x[0][j]<<' ';
            // }cout<<endl;
            // cout<<endl;
            // if(cnt!=buck[i]){
            //     cout<<"???"<<endl;
            // }
            // cout<<endl;
            // cout<<111<<endl;
            if(buck[i]==m){
                //cout<<i<<endl;
                ll ans = x[1][0];
                for(int j = 0;j<x[1].size();j++){
                    ans &= x[1][j];
                    //cout<<x[1][j]<<' ';
                    //if(x[1][j]!=x[1][j-1]-1){
                        //cout<<"what?"<<endl;
                    //}
                }cout<<ans<<endl;
                return 0;
            }
            memset(buck, 0, sizeof(buck));
            for(int j = 0;j<x[0].size();j++){
                for(int k = 31;k>=0;k--){
                    buck[k] += (x[0][j]>>k)&1;
                    //cout<<((x[0][j]>>k)&1)<<' ';
                }//cout<<endl;
            }
            //cout<<endl<<endl;
            x[1].assign(0, 0);
        }
    }ll ans = x[0][0];
    for(int i = 1;i<=m;i++){
        ans &= x[0][i];
    }cout<<ans<<endl;
}/*
*/