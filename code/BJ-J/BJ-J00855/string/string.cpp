#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,mod=1e9+7,INF=1e18;
struct node{
    int cnt;
    char c;
} a[N],b[N];
int id=0,idz=0,s[N];
int get(int l,int r,int idl){
    int sum=s[id+1],idls=0;
    bool op=1;
    for(int j=id;j>=idz+1;j--){
        sum+=b[j].cnt;
        if(sum>r){
            a[++idls]=b[j];
            sum-=b[j].cnt;
            sum=max(sum,l);
            a[idls].cnt=r-sum;
            break;
        }
        if(sum>=l&&op){
            id=min(id,j);
            a[++idls]=b[j];
            op=0;
            a[idls].cnt=sum-l;
        }else if(sum>=l){
            a[++idls]=b[j];
        }
    }
    int ans=0;
    for(int i=1;i<=idls;i++){
        if(a[i].c!=b[idl].c){
            ans+=a[i].cnt;
        }
    }
    return ans;
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].cnt>>a[i].c;
        sum+=a[i].cnt;
    }
    sum++;
    bool op;
    if(sum%2==0)op=1;
    else op=0;
    sum/=2;
    int sum1=0;
    bool c=1;
    for(int i=1;i<=n;i++){
        sum1+=a[i].cnt;
        if(sum1>sum&&c){
            sum1-=a[i].cnt;
            b[++id]=a[i];
            b[id].cnt=sum-sum1-op;
            if(b[id].cnt==0)id--;
            idz=id;
            b[++id]=a[i];
            b[id].cnt=a[i].cnt-(sum-sum1-op)-op;
            if(b[id].cnt==0)id--;
            sum1+=a[i].cnt;
            c=0;
        }else{
            b[++id]=a[i];
            if(b[id].cnt==0)id--;
        }
    }
    for(int i=id;i>idz;i--){
        s[i]=s[i+1]+b[i].cnt;
    }
    sum1=0;
    int ans=0;
    for(int i=1;i<=idz;i++){
        ans+=get(sum1,sum1+b[i].cnt,i);
        sum1+=b[i].cnt;
    }
    cout<<ans;
    return 0;
}
