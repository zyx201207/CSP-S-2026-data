#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin >> n >> m;
    vector <long long> a(n);
    for(int i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a.begin(),a.end());
    bool f1=1,f2=1;
    long long l1=a[1]-a[0];
    for(int i=0;i<n;i++){
        if(a[i]!=i+1){
            f1=0;
        }
        if(a[i+1]-a[i]!=l1&&i!=n-1){
            f2=0;
        }
    }
    if(f1==1){
        long long i=1,cnt=0;
        while(m-i>=0){
            m-=i;
            i++;
            cnt++;
            //cout << m <<" ";
        }
        //cout << endl;
        cout << cnt +1<< endl;
        return 0;
    }
    else if(f2==1){
        //cout << "f2";
        long long i=l1,cnt=0;
        while(m-i>=0){
            m-=i;
            i+=l1;
            cnt++;
        }
        cout << cnt +1<< endl;
        return 0;
    }
    vector <vector<long long>> dp(n,vector<long long>(m+1,1));
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            long long l=a[i]-a[j];
            for(int k=0;k+l<=m;k++){
                dp[i][k]=max(dp[i][k],dp[j][k+l]+1);
            }
        }
    }
    long long max_cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=m;j++){
            max_cnt=max(max_cnt,dp[i][j]);
        }
    }
    cout << max_cnt;
    return 0;
}
