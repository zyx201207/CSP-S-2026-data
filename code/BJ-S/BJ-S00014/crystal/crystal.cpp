#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010];long long sum=0,lg=0,ans=0;long long l=1,r=1;
bool cmp(long long x,long long y){
    return x<y;
}
int wm(){
     while(sum<=m){
        sum+=(r-l)*(a[r]-a[r-1]);
        if(r==n){
            if(sum>m){
                sum=sum-(r-l)*(a[r]-a[r-1]);
            r--;
            ans=max(ans,r-l+1);
            r++;return 1;
            }
            ans=max(ans,r-l+1);
            return 1;
        }
        else if(sum>m){
            sum=sum-(r-l)*(a[r]-a[r-1]);
            r--;
            ans=max(ans,r-l+1);
            r++;
            return 0;
        }
       else {
           r++;
       }
    }
   return 0;
}
int ml(){
    sum+=(r-l)*(a[r]-a[r-1]);
    while(sum>=m){
        
        l++;
        sum=sum-(a[r]-a[l]);
        if(r==n){
            ans=max(ans,r-l+1);
            return 1;
        }
        if(sum<m){
            r++;
            ans=max(ans,r-l+1);
            return 3;
        }else if(sum==m){
            r++;sum+=(r-l)*(a[r]-a[r-1]);
            ans=max(ans,r-l+1);
        }
    }
    return 3;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[0]=a[1];
    sort(a,a+n+1,cmp);
    long long k=wm();
    while(1){
        if(k==1){
        cout<<ans;return 0;
    }else if(k==0){
        k=ml();
    }else if(k==3)k=wm();
    }
    
    return 0;
}