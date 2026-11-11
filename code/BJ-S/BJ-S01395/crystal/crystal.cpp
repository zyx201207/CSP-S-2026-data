#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
pair<long long,int> a[500005];
long long b[500005];
pair<int,long long> t[500005];
long long pre[500005];
int sum[500005];
int ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i].first,b[i]=a[i].first;
    sort(b+1,b+1+n);
    int len=unique(b+1,b+1+n)-b-1;
    for(int i=1;i<=n;i++) a[i].second=lower_bound(b+1,b+1+len,a[i].first)-b;
    //for(int i=1;i<=n;i++) cout<<a[i].first<<" -> "<<a[i].second<<" | ";
    //cout<<endl;
    for(int i=1;i<=n;i++){
        t[a[i].second].first++;
        t[a[i].second].second=a[i].first;
    }
    for(int i=1;i<=len;i++) {
        pre[i]=pre[i-1]+t[i].second*t[i].first;
        sum[i]=sum[i-1]+t[i].first;
    }
    //for(int i=1;i<=n;i++) cout<<i<<":"<<sum[i]<<endl;
    ans=t[1].first;
    for(int i=2;i<=len;i++){
        if((t[i].second*sum[i]-pre[i])<=m){
            ans=max(ans,sum[i]);
            continue;
        }
        int l=1,r=i-1;
        while(l<r){
            int mid=(l+r)/2;
            //cout<<mid<<" "<<l<<" "<<r<<endl;
            if(abs(t[i].second*(sum[i]-sum[mid-1])-(pre[i]-pre[mid-1]))<=m) r=mid;
            else l=mid+1;
        }
        int res=sum[i]-sum[l-1];
        long long rem=m-abs(t[i].second*(sum[i]-sum[l-1])-(pre[i]-pre[l-1]));
        long long cha=t[i].second-t[l-1].second;
        while(rem>=cha) rem-=cha,res++;
        ans=max(ans,res);
        //cout<<i<<":"<<res<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
/*
in:
5 5
1 2 4 8 9
out:
3
*/
