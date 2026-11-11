#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[200005];
long long dist[200005];
bool flag=1;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        dist[i]=dist[i-1]+a[i];
        if(c[i]!=c[i-1] && i!=1) flag=0;
    }

    if(flag){
        cout<<0;
        return 0;
    }

    long long mid=ceil(dist[n]/2.0);
    char midc;
    int mida;
    for(int i=1;i<=n;i++){
        if(dist[i]>=mid){
            mida=i;
            midc=c[i];
            break;
        }
    }
    char left[100005],right[200005];
    long long lc[100005],rc[200005];
    if(dist[n]%2==1){
        for(int i=1;i<mida;i++){
            left[i]=c[i];
            lc[i]=a[i];
        }
        lc[mida]=mid-1-dist[mida-1];
        if(lc[mida]!=0) left[mida]=c[mida];
        rc[mida]=dist[mida+1]-mid;
        if(rc[mida]!=0) right[mida]=c[mida];
        for(int i=mida+1;i<=n;i++){
            right[i]=c[i];
            rc[i]=a[i];
        }
    }
    else{
        for(int i=1;i<mida;i++){
            left[i]=c[i];
            lc[i]=a[i];
        }
        lc[mida]=mid-dist[mida-1];
        left[mida]=c[mida];
        rc[mida]=dist[mida]-mid;
        right[mida]=c[mida];
        for(int i=mida+1;i<=n;i++){
            right[i]=c[i];
            rc[i]=a[i];
        }
    }
    reverse(right+mida,right+n+1);
    int ans=0;
    for(int i=1;i<mida;i++){
        ans+=abs(lc[i]-rc[i]);
    }
    cout<<ans;
    return 0;
}
