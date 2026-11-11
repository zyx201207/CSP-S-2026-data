#include<bits/stdc++.h>
using namespace std;
int n;
const int N=5e5;
long long a[N];
long long check(){
    long long maxn=0;
    long long cnt=1;
    for(int i=1;i<=n;i++){
        if((a[i-1]==a[i]&&a[i]==a[i+1])||(a[i+1]==a[i]&&i==1)||(a[i-1]==a[i]&&i==n)){
            cnt++;
        }else{
            maxn=max(maxn,cnt);
            cnt=1;
        }
    }
}
void dfs(int step){
    long long maxn=0;
    while(step<=m){
        for(int i=1;i<=n;i++){
            a[i]++;
            dfs(step+1);
            a[i]--;
            maxn=max(maxn,check());
        }
    }
    cout<<maxn;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    for(int i=0;i<=N;i++){
        a[i]=LONG_MIN;
    }
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
