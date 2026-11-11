#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0;
const int maxn=1e12+5;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    vector<int> arr(n+5,0);
    vector<vector<int> >brr(n+5,vector<int>(n+5,0));
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    vector<vector<int> >dp(n+5,vector<int>(n+5,0));
    //sort(arr.begin()+1,arr.end()+1);
    for(int i=1;i<n;i++){

        for(int j=i+1;j<=n;j++){
            brr[i][j]=arr[j]-arr[i];
        }

    }

    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }


    int left=1;
    int right=n/2;
    while(left<right&&right<=n){
        int num=0,k=0;
        for(int i=1;i<=right;i++){
            num+=brr[right][i];
            k++;
        }
        if(num<m&&right==n){
        cout<<k;
            return 0;
        }
        if(num<m){
            right++;
            ans=max(k,ans);
        }
        else{
            left++;
        }
    }
   if(ans==0){
        cout<<1;
        return 0;
    }
    cout<<ans;
    return 0;
}
