#include<bits/stdc++.h>
using namespace std;
#define int long long
int b[200005],e[200005],x[200005];
char c[200005],c1[200005],c2[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,sum=0;
    cin>>n;
    if(n==1){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>x[i]>>c[i];
        sum+=x[i];
    }
    int now=0,cnt1=0,cnt2=0;
    if(sum%2==1){
    for(int i=1;i<=n;i++){
        if(now+1<=(sum+1)/2){
            b[++cnt1]=(sum+1)/2-now-1;
            c1[cnt1]=c[i];
        }
        now+=x[i];
        if(now>=(sum+1)/2){
            e[++cnt2]=now-(sum+1)/2;
            c2[cnt2]=c[i];
        }
    }
    }
    else{
    for(int i=1;i<=n;i++){
        if(now+1<=sum/2){
            b[++cnt1]=sum/2-now;
            c1[cnt1]=c[i];
        }
        now+=x[i];
        if(now>sum/2){
            e[++cnt2]=now-sum/2;
            c2[cnt2]=c[i];
        }
    }
    }
    b[cnt1+1]=0;
    e[0]=0;
    int cnt=0;
    for(int i=cnt1,j=1;i>=1&&j<=cnt2;){
        if(b[i]<e[j]){
            if(c1[i]!=c2[j]){
                cnt+=(b[i]-max(b[i+1],e[j-1]));
            }
            i--;
        }
        else{
            if(c1[i]!=c2[j]){
                cnt+=(e[j]-max(b[i+1],e[j-1]));
            }
            j++;
        }
    }
    cout<<cnt;
    return 0;
}
