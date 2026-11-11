#include<bits/stdc++.h>
using namespace std;
int a[114514],n,m;
/*int A(int rst,int f,int ix){
    //cout<<"S"<<f<<' '<<ix<<' '<<a[ix]<<' '<<rst<<'\n';
    if(f>m)return rst;//over depth
    if(ix>n)return rst;//over index
    int ans=0;
    for(int i=ix+1;i<=n;i++){
        ans=max(ans,A(rst&a[i],f+1,i));
    }//cout<<"E"<<f<<' '<<ix<<' '<<a[ix]<<' '<<rst<<' '<<ans<<'\n';
    return ans;
}*/
int dp[114514];
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);

    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];dp[i]=a[i];
    };

    for(int t=1;t<m;t++){
        for(int i=n;i>=1;i--){
            int as=0;
            for(int j=t;j<i;j++)
                as=max(as,a[i]&dp[j]);
            dp[i]=as;
        }
    }

    for(int i=1;i<=n;i++)ans=max(ans,dp[i]);
    cout<<ans;
    return 0;

}
