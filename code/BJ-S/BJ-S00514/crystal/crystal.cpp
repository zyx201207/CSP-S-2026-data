#include<bits/stdc++.h>
using namespace std;
int n;
long long m,cnt,sum,minn=1e18,maxs=-1e18,id;
long long a[500005];
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        sum=1;
        while(a[i]==a[i+1]&&i+1<=n){
            sum++;
            i++;
        }
        if(sum>maxs){
            maxs=sum;
        }
    }
    for(int i=1;i<n;i++){
        if(a[i]-a[i-1]+a[i+1]-a[i]<minn){
            minn=a[i]-a[i-1]+a[i+1]-a[i];
            id=i;
        }
    }
    if(id>=2&&id<n){
        cnt=1;
        long long x=1;
        long long h=m;
        while(h>0){

            long long mindiff=min(a[id]-a[id-x],a[id+x]-a[id]);
            long long maxdiff=max(a[id]-a[id-x],a[id+x]-a[id]);
            if(h>=mindiff&&id-x>=1&&id+x<=n)
            {
                h-=mindiff;
                cnt++;
            }
            else if(h>=a[id+x]-a[id]&&id-x<=0&&id+x<=n)
            {
                h-=a[id+x]-a[id];
                cnt++;
            }
            else if(h>=a[id]-a[id-x]&&id-x>=1&&id+x>n)
            {
                h-=a[id]-a[id-x];
                cnt++;
            }
            else break;
            if(h>=maxdiff){
                h-=maxdiff;
                cnt++;
            }
            if(h==m){
                cnt=maxs;
                break;
            }
            x++;
        }
    }
    else if(id==1){
        cnt=1;
        long long x=1;
        long long h=m;
        while(h>0){
            if(h>=a[id+x]-a[id]&&id+x<=n)
            {
                h-=a[id+x]-a[id];
                cnt++;
                x++;
            }
            else break;
        }
    }
    cout<<max(cnt,maxs);
    return 0;
}
