#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct ax{
    char x;
    ll s;
};
ll n,m,k,qj[int(1e5+5)],ans,res=0;
ax a[int(1e5+5)],ax[int(1e5+5)],ay[int(1e5+5)];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].s>>a[i].x;
        qj[i]=qj[i-1]+a[i].s;
    }
    ans=qj[n];
    ll ank=ans/2;
    int plo=0;
    if(ans%2==1){
        plo=1;
    }
    for(int i=1;i<=n;i++){
        if(qj[i]>ank){
            m=i;
            break;
        }
    }
    for(int i=1;i<m;i++){
        ax[i].x=a[i].x;
        ax[i].s=a[i].s;
    }
    for(int i=n;i>m;i--){
        ay[i].x=a[i].x;
        ay[i].s=a[i].s;
    }
    ax[m].x=a[m].x;
    ay[n-m+1].x=a[m].x;
    ax[m].s=ank-qj[m-1];
    ay[n-m+1].s=qj[m]-qj[m-1]-ax[m].s-plo;
    for(ll hx=1,hy=n;hx<=hy; ){
        ll zc=min(ax[hx].s,ay[hy].s);
        if(ax[hx].x!=ay[hy].x){
            res+=zc;
        }
        ax[hx].s-=zc;
        ay[hy].s-=zc;
        if(ax[hx].s<=0){
            hx++;
        }
        if(ay[hy].s<=0){
            hy--;
        }
    }
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


