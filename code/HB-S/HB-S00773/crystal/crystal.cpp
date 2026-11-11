#include<bits/stdc++.h>
using namespace std;
#define MAXN 500010
#define ll long long
int n,ans;
ll m,len,tmp,arr[MAXN],sum[MAXN],dist[MAXN];
struct part{
    int st,ed,l;
}p[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>arr[i];
    sort(arr+1,arr+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+arr[i];
    }
    p[++len].st=1;
    p[len].l=1;
    for(int i=2;i<=n;i++){
        int ds1=arr[i]-arr[i-1];
        dist[i]=arr[i]*p[len].l-(sum[i-1]-sum[p[len-1].ed]);
        if(dist[i]<=m){
            p[len].ed=i;
        }
        else{
            p[++len].st=i;
            p[len].ed=i;
            dist[i]=0;
        }
        p[len].l++;
    }
    for(int i=2;i<=len;i++){
        int j=p[i].st-1,flag=1;
        while(flag){
            if(arr[p[i].ed]-arr[j]+dist[p[i].ed]>m) flag=0;
            else{
                dist[p[i].ed]=dist[p[i].ed]+arr[p[i].ed]-arr[j];
                p[i].l++;
                j--;
            }
        }
        p[i].st=j+1;
        flag=1;
        tmp=0;
        while(flag){
            if(arr[p[i].ed-1]-arr[j]>tmp && arr[p[i].ed-1]-arr[j]>=tmp+(arr[p[i].ed]*p[i].l-(sum[p[i].ed]-sum[j]))) flag=0;
            else{
                if(arr[p[i].ed-1]-arr[j]>tmp){
                    tmp=tmp+(arr[i]*p[i].l-(sum[p[i].ed]-sum[j]));
                    p[i].ed--;
                }
                p[i].l++;
                j--;
            }
        }
        p[i].st=j+1;
    }
//    for(int i=1;i<=len;i++) cout<<p[i].st<<" "<<p[i].ed<<" "<<p[i].l<<"\n";
//    for(int i=1;i<=n;i++) cout<<dist[i]<<" ";
//    cout<<"\n";
    for(int i=1;i<=len;i++) ans=max(ans,p[i].l);
    cout<<ans;
    return 0;
}
