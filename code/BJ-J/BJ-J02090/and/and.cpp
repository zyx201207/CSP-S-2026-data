#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N][35];
int n,m,x[N],maxlen,ans;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>x[i];
    sort(x+1,x+1+n);
    for(int i=1;i<=n;++i){
        int j=0;
        while(x[i]){
            a[i][++j]=x[i]&1;
            a[n+1][j]+=x[i]&1;
            x[i]>>=1;
        }
        maxlen=max(j,maxlen);
    }
    int up=1,down=n;
    for(int i=maxlen;i>=1;--i){
        if(a[n+1][i]<m)continue;
        int uped=up,downed=down;
        for(int j=n;j>=1;j--){
            if(a[j][i]){
                down=j;
                break;
            }
        }
        int left=up,right=down;
        while(left<right){
            int mid=(left+right)>>1;
            if(a[mid][i])right=mid;
            else left=mid+1;
        }
        up=left;
        for(int j=uped;j<up;j++)
            for(int k=1;k<=32;++k)
                a[n+1][k]-=a[j][k];
        for(int j=downed;j>down;j--)
            for(int k=1;k<=32;++k)
                a[n+1][k]-=a[j][k];
    }
    for(int i=32;i>=1;--i){
        ans<<=1;
        if(a[n+1][i]>=m)ans++;
    }
    cout<<ans;
}
//无问题
