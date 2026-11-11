#include<bits/stdc++.h>
using namespace std;
const int MAXN=200000+2;
int n,a[MAXN];
long long nl,nr,x,y,sum,last[MAXN],pre[MAXN],l,r,ln,rn,ans;
char c[MAXN];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        pre[i]=sum+1ll;
        sum+=1ll*a[i];
        last[i]=sum;
    }
    for(int i=1;i<=n;i++){
        if(sum/2ll+(sum%2ll)>=pre[i]&&sum/2ll+(sum%2ll)<=last[i])
            x=i;
    }
    for(int i=1;i<=n;i++){
        if(sum/2ll+1ll>=pre[i]&&sum/2ll+1ll<=last[i])
            y=i;
    }
    l=1;r=sum;ln=1;rn=n;
    while(1){
        if(l>=r||ln==rn)
            break;
        if(l==sum/2ll+(sum%2ll)&&r==sum/2ll+1ll){
            ans+=(c[x]!=c[y]);
            break;
        }
        nl=min(sum/2ll+(sum%2ll),pre[ln+1]);
        nr=max(sum/2ll+1ll,last[rn-1]);
        if(nl-l>r-nr){
            ans+=(r-nr)*(c[ln]!=c[rn]);
            l=l+r-nr;r=nr;rn--;
        }else if(nl-l==r-nr){
            ans+=(r-nr)*(c[ln]!=c[rn]);
            l=nl;r=nr;ln++;rn--;
        }else{
            ans+=(nl-l)*(c[ln]!=c[rn]);
            r=r-nl+l;l=nl;ln++;
        }
    }
    cout<<ans<<endl;
}
