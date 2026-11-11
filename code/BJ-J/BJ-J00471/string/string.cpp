#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
int n,a[maxn],len,sum[maxn][26],pre[maxn],ans;
signed num[maxn];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char c;
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
        cin>>c;
        num[i]=c-'a';
        len+=a[i];
        for(int j=0;j<26;j++)sum[i][j]=sum[i-1][j];
        sum[i][num[i]]=sum[i-1][num[i]]+a[i];
    }
    for(int i=1;i<=n;i++){
        int tgtl=len-pre[i-1],tgtr=len-pre[i]+1;
        signed lr,rr,l=1,r=n,mid;
        while(l<=r){
            mid=(l+r)/2;
            if(pre[mid-1]+1<=tgtl&&pre[mid]>=tgtl){
                lr=mid;
                break;
            }
            if(pre[mid-1]+1>tgtl)r=mid-1;
            if(pre[mid]<tgtl)l=mid+1;
        }
        l=0,r=n;
        while(l<=r){
            mid=(l+r)/2;
            if(pre[mid-1]+1<=tgtr&&pre[mid]>=tgtr){
                rr=mid;
                break;
            }
            if(pre[mid-1]+1>tgtr)r=mid-1;
            if(pre[mid]<tgtr)l=mid+1;
        } 
        if(lr==rr&&num[i]!=num[lr]){
            ans+=a[i];
        }else{
            if(num[i]!=num[rr])ans+=pre[rr]-tgtr+1;
            if(num[i]!=num[lr])ans+=tgtl-pre[lr-1];
            ans+=pre[lr-1]-pre[rr]-sum[lr-1][num[i]]+sum[rr][num[i]];
        }
    }
    cout<<ans/2;
    return 0;
}