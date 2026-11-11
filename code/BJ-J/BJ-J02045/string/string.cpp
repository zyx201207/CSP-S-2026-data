#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    char x[N],x1[N],x2[N];
    int a[N],a1[N],a2[N];
    cin>>n;
    int ans=0,cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt+=a[i];
        cin>>x[i];
    }
    int l=cnt/2;
    int r;
    if(cnt%2==0) r=l+1;
    else{
        r=l+2;
    }
    int cnt2=0;
    for(int i=1;i<=n;i++){
        if(cnt2+a[i]<=l){
            cnt2+=a[i];
            a1[i]=a[i];
            x1[i]=x[i];
            continue;
        }
        a1[i]=l-cnt2;
        x1[i]=x[i];
        break;
    }
    int p=0;
    cnt2=0;
    for(int i=n;i>=1;i--){
        p++;
        if(cnt2+a[i]<=cnt-r+1){
            cnt2+=a[i];
            a2[p]=a[i];
            x2[p]=x[i];
            continue;
        }
        a2[p]=cnt-r+1-cnt2;
        x2[p]=x[i];
        break;
    }
    int m=1,v=1;
    while(p>0){
        if(a1[m]>a2[v]){
            if(x1[m]==x2[v]){
                a1[m]-=a2[v];
                v++;
                p--;
            }
            else{
                ans+=a2[v];
                a1[m]-=a2[v];
                v++;
                p--;
            }
        }
        if(a1[m]==a2[v]){
            if(x1[m]!=x2[v]){
                ans+=a1[m];
                v++;
                m++;
                p--;
            }
            else{
                v++;
                m++;
                p--;
            }
        }
        if(a1[m]<a2[v]){
            if(x1[m]==x2[v]){
                a2[v]-=a1[m];
                m++;
            }
            else{
                ans+=a1[m];
                a2[v]-=a1[m];
                m++;
            }
        }
    }
    cout<<ans;
    return 0;
}

