#include<bits/stdc++.h>
using namespace std;
long long a[5000000];
int dp[500000000];
bool ause[5000000];
int main(){
    long long n,m;
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //sort(a,a+n);//from small to big!!!
    long long mymin=a[0],mymax=a[0];
    for(int i=0;i<n;i++){
        if(a[i]<mymin)mymin=a[i];
        if(a[i]>mymax)mymax=a[i];
    }

    int myans =-1;
    for(int k=mymin;k<=mymax;k++){
        for(int i=0;i<n;i++)ause[i]=1;
        for(int i=0;i<m;i++)dp[i]=0;

        for(int i=0;i<m;i++){
            for(int j=n-1;j>=0;j--){
                //dp[i]=dp[i-1];
                //if(i==0)dp[i]=0;
                if(k==a[j]&&ause[j]==1&&i==0){
                    dp[i]++;
                    for(int i=0;i<m;i++)dp[i]=max(dp[i],dp[0]);
                    ause[j]=0;
                    //cout<<"!!! "<<a[j]<<endl;;
                    //for(int i=0;i<m;i++)//cout<<dp[i]<<" ! ";

                    //cout<<endl;
                }else if(i>=k-a[j]&&k>=a[j]&&ause[j]==1){
                    if(dp[i-k+a[j]-1]+1>dp[i-1]){
                        ause[j]=0;
                        //cout<<"let"<<a[j]<<"go up"<<k-a[j]<<"to"<<k<<"#########"<<dp[i]<<"->"<<dp[i-k+a[j]]+1;
                    }
                    ////cout<<"let"<<a[j]<<"go up"<<k-a[j]<<"to"<<k<<endl<<dp[i]<<"->"<<dp[i-k+a[j]]+1;
                    //dp[i]=max(dp[i-k+a[j]-1]+1,dp[i-1]);
                    dp[i]++;
                    for(int i=0;i<m;i++)dp[i]=max(dp[i],dp[0]);
                    for(int i=0;i<m;i++)dp[i]=dp[i];
                }
            }
            //cout<<endl;
            //for(int i=0;i<m;i++)//cout<<dp[i]<<" ";
            //cout<<endl;
        }

        //cout<<"___________________"<<dp[m-1]<<"======="<<endl;
        if(dp[m-1]>myans)myans=dp[m-1];
    }
//    for(int i=0;i<n;i++){
//        //cout<<a[i]<<" ";
//    }
    cout<<myans<<endl;
    return 0;

}
