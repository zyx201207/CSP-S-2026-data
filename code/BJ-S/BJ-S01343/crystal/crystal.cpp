#include<bits/stdc++.h>
#define int long long
using namespace std;
int s[500005];
int mul[500005];
int s1[500005];
__int128 alls[500005];
int n,m;
__int128 sum=0;
bool judge(int i,int j){
    __int128 allsum=alls[j]-alls[i-1];
    __int128 sum11=(i-1)*(s[j]-s[i-1]);
    allsum-=sum11;
    return allsum>m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    sort(s+1,s+n+1);
    for(int i=2;i<=n;i++){
        s[i]-=s[1];
    }
    s[1]=0;
    for(int i=1;i<=n;i++){
        mul[i]=s[i]-s[i-1];
        //if(i==1) cout<<"  ";
        //else cout<<mul[i]<<' ';
    }
    //cout<<'\n';
    for(int i=2;i<=n;i++){
        s1[i]=(i-1)*(mul[i]);
        sum+=s1[i];
        alls[i]=sum;
        //cout<<s1[i]<<' ';
    }
    //int l=1,r=n;
    //while(sum>m){
    //    if()
    //}
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=(l+r+1)/2;
            if(judge(mid,i)){
                l=mid+1;
                //cout<<1;
            }else{
                r=mid-1;
                //cout<<2;
            }
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
