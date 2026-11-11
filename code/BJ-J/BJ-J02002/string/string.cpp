#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010],ha[200010],xa[200010],la[200010];
char c[200020],hc[200020],xc[200010],lc[200010];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,flag=1;
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        cnt+=a[i];
        if(c[i]!=c[i-1]&&i!=1){
            flag=0;
        }
    }
    if(flag==1){
        cout<<"0";
        return 0;
    }
    int j=0,k=1,hflen=0,s=0;
    if(cnt%2==0) hflen=cnt/2;
    else hflen=cnt/2+1;
    while(j<hflen){
        if(j+a[k]<=hflen){
            j+=a[k];
            ha[k]=a[k];
            hc[k]=c[k];
        }else{
            ha[k]=hflen-j;
            hc[k]=c[k];
            s=j+a[k]-hflen;
            j=hflen+1;
        }
        k++;
    }
    la[1]=s,lc[1]=c[k-1];
    if(la[1]==0){
        lc[1]=c[k];
    }
    int top=2;
    for(int i=k;i<=n;i++){
        la[top]=a[i];
        lc[top]=c[i];
        top++;
    }
    int ans=0,topx=1,topl=1,i=1,m=1,g=1;
    while(i<=cnt-hflen){
        if(xc[topx]!=lc[topl]){
            ans++;
        }
        if(m==xa[topx]){
            m=1;
            topx++;
        }
        if(g==la[topl]){
            g=1;
            topl++;
        }
        i++;
        m++;
        g++;
    }
    cout<<ans;
}
