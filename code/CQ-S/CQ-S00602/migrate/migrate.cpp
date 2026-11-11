#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000005;
vector<int> v;
int n,d,ans,a[N],to[N],dp[N][7];
void solve(vector<int> &a){
    if(a.empty())  return void();
    int n=a.size();fill(dp[0],dp[0]+7,0);
    for(int i=1;i<n;i++){
        to[i]=to[i-1];
        while(a[to[i]]<a[i]-d)  to[i]++;
    }
    for(int i=1;i<n;i++){
        int j=to[i],lst=i-j;
        if(lst==1)  dp[i][0]+=dp[j][0];
        else if(lst==2)  dp[i][0]+=dp[j][1];
        else  dp[i][0]+=dp[j][2];
        if(n-i>=2){
            dp[i][1]=i-to[i+1];
            if(lst==1){
                if(j<to[i+1])  dp[i][1]+=dp[j][0];
                else  dp[i][1]+=dp[j][4];
            }
            else if(lst==2){
                if(j+1<to[i+1])  dp[i][1]+=dp[j][1];
                else if(j<to[i+1])  dp[i][1]+=dp[j][3];
                else  dp[i][1]+=dp[j][5];
            }
            else{
                if(j+1<to[i+1])  dp[i][1]+=dp[j][2];
                else if(j<to[i+1])  dp[i][1]+=dp[j][3];
                else  dp[i][1]+=dp[j][5];
            }
        }
        if(n-i>=3){
            dp[i][2]=min(i,to[i+2])-to[i+1];
            if(lst==1){
                if(j<to[i+1])  dp[i][2]+=dp[j][0];
                else if(j<to[i+2])  dp[i][2]+=dp[j][4];
                else  dp[i][2]+=dp[j][6];  
            }
            else if(lst==2){
                if(j+1<to[i+1])  dp[i][2]+=dp[j][1];
                else if(j<to[i+1])  dp[i][2]+=dp[j][3];
                else if(j<to[i+2])  dp[i][2]+=dp[j][5];
                else  dp[i][2]+=dp[j][6];
            }
            else{
                if(j+1<to[i+1])  dp[i][2]+=dp[j][2];
                else if(j<to[i+1])  dp[i][2]+=dp[j][3];
                else if(j<to[i+2])  dp[i][2]+=dp[j][5];
                else dp[i][2]+=dp[j][6];
            }
        }
        if(n-i>=2){
            if(lst==1){
                if(j<to[i+1])  dp[i][3]+=dp[j][0];
                else  dp[i][3]+=dp[j][6];
            }
            else if(lst==2){
                if(j+1<to[i+1])  dp[i][3]+=dp[j][1];
                else if(j<to[i+1])  dp[i][3]+=dp[j][3];
                else  dp[i][3]+=dp[j][6];
            }
            else{
                if(j+1<to[i+1])  dp[i][3]+=dp[j][2];
                else if(j<to[i+1])  dp[i][3]+=dp[j][3];
                else  dp[i][3]+=dp[j][6];
            }
        }
        dp[i][4]=lst;
        if(lst==1)  dp[i][4]+=dp[j][4];
        else  dp[i][4]+=dp[j][5];
        if(n-i>=2){
            dp[i][5]=to[i+1]-to[i];
            if(lst==1){
                if(j<to[i+1])  dp[i][5]+=dp[j][4];
                else  dp[i][5]+=dp[j][6];
            }
            else{
                if(j<to[i+1])  dp[i][5]+=dp[j][5];
                else  dp[i][5]+=dp[j][6];
            }
        }
    }
    for(int i=0;i<n;i++)
        ans+=dp[i][0],fill(dp[i],dp[i]+7,0);
}
void solve(){
    cin>>n>>d,ans=0;
    for(int i=1;i<=n;i++)  cin>>a[i];
    for(int i=1,lst=0;i<=n;i++){
        if(i==n||a[i+1]-a[i]>d){
            for(int j=lst+1;j<=i;j++)
                v.push_back(a[j]);
            solve(v),v.clear(),lst=i;
        }
    }
    return cout<<ans<<"\n",void();
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int c,t;cin>>c>>t;while(t--)  solve();
}