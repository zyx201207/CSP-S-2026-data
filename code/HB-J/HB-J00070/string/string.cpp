#include<bits/stdc++.h>
using namespace std;
using int64=long long;
struct node{
    int64 left,right;
    char c;
}sum[200005];
int64 a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int64 n,x;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>sum[i].c;
        sum[i].left=sum[i-1].right+1;
        sum[i].right=sum[i-1].right+a[i];
    }
    int64 l=1,r=n,ans=0,lsum=1,rsum=sum[n].right;
    while(l<=r){
        int l1=max(sum[l].left,lsum),r1=sum[l].right;
        int l2=sum[r].left,r2=min(sum[r].right,rsum);
        int line1=r1-l1+1,line2=r2-l2+1,minn=min(line1,line2);
        if(sum[l].c!=sum[r].c) ans+=minn;
        if(line1>line2) r--;
        else if(line1==line2) l++,r--;
        else l++;
        lsum+=minn;
        rsum-=minn;
    }
    cout<<ans;
    return 0;
}
