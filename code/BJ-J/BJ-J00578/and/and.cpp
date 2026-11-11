#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int num[32],n,m,a[N],ans;
vector<int> unable[32];
bool vis[N];
inline void bitslove(int idx){
    int b=a[idx];
    for(int i=30;i>=0;i--){
        if(b>=(1<<i)){
            num[i]++;
            b-=(1<<i);
        }
        else{
            unable[i].push_back(idx);
            //cout<<a[idx]<<" is pushed in "<<i<<'\n';
        }
    }
    return;
}
inline void bitdown(int idx){
    int b=a[idx];
    for(int i=30;i>=0;i--){
        if(b>=(1<<i)){
            num[i]--;
            b-=(1<<i);
        }
    }
    return;
}
inline void down(int idx){
    //cout<<"down at "<<idx<<'\n';
    for(vector<int>::iterator it=unable[idx].begin();it!=unable[idx].end();it++){
        if(vis[*it]==true){continue;}
        //cout<<"    down the "<<*it<<":"<<a[*it]<<'\n';
        bitdown(*it);
        vis[*it]=true;
        //cnt--;
    }
    return;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    //cnt=n;
    //cout<<"test3"<<'\n';
    for(int i=0;i<n;i++){
        cin>>a[i];
        //cout<<"test2"<<'\n';
        bitslove(i);
        vis[i]=false;
    }
    //cout<<"test1"<<'\n';
    //for(int i=0;i<32;i++){
    //    cout<<i<<" "<<num[i]<<'\n';
    //}
    for(int i=30;i>=0;i--){
        //cout<<i<<" "<<num[i]<<'\n';
        //for(int j=0;j<5;j++){
        //    cout<<j<<" "<<num[j]<<'\n';
        //}
        //cout<<'\n';
        if(num[i]>=m){
            ans+=(1<<i);
            down(i);
        }
        //if(cnt==m){
        //    break;
        //}
    }
    cout<<ans<<'\n';
    return 0;
}
