include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    int maxx=0,max_id=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>maxx){
            maxx=a[i];
            max_id=i;
        }
    }
    vector<long long> dp(m+1,0);
    dp[1]=maxx;
    vector<bool> used(n,false);
    used[max_id]=true;
    for(int i=2;i<=m;i++){
        long long max_result_id=0;
        for(int j=0;j<n;j++){
            if(used[j]) continue;
            long long result=dp[i-1]&a[j];
            if(result>dp[i]){
                max_result_id=j;
                dp[i]=result;
            }
        }
        used[max_result_id]=true;
    }
    cout<<dp[m];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
