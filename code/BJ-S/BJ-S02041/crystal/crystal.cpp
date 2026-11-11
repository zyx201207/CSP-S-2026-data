#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fo(i,j,k) for(register int i=j;i<=k;i++)
const int N=5e5;
int n,m,x,y,k,ans=1,cnt=0,a[N];
bool tezhengab(){
    int k=a[2]-a[1];
    fo(i,3,n) if(a[i]-a[i-1]!=k) return 0;
    return 1;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    fo(i,1,n) cin>>a[i];
    if(tezhengab()){
       int i=1,k=a[2]-a[1];
       fo(j,1,n){
           m-=k*i;i++;
           if(m>=0) ans++;
           else break;
       }
       cout<<ans;
    }
    else{
        sort(a+1,a+n+1);
        for(int maid=n;maid>=1;maid--){
            int ma=a[maid];
            //cout<<ma<<endl;
            for(int i=maid-1;i>=1;i--){
                //cout<<m<<(ma-a[i])<<endl;
                int cur=ma-a[i];
                if(m>=cur) m=m-(cur);
                else break;
                ans++;
            }
            cnt=max(ans,cnt);
        }
        cout<<cnt;
    }
    return 0;
}
