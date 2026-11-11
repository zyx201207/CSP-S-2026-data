#include<bits/stdc++.h>
using namespace std;
struct pq{
    long long int l,r;
};
pq cnt;
long long int n,a[300005],ans,s,sum,q;
char c[300005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        s+=a[i];
    }
    cnt.l=n,cnt.r=a[n],sum=1;
    for(int i=1;i<=n;i++){
        if(sum>s/2){
            break;
        }
        sum+=a[i];
        q=a[i];
        if(cnt.r>q){
            if(c[cnt.l]!=c[i]){
                ans+=q;
            }
            cnt.r-=q;
            continue;
        }else{
            if(c[cnt.l]!=c[i]){
                ans+=cnt.r;
            }
            q-=cnt.r;
            cnt.l-=1;
            cnt.r=a[cnt.l];
        }
        while(a[cnt.l]<=q){
            if(c[cnt.l]!=c[i]){
                ans+=a[cnt.l];
            }
            q-=a[cnt.l];
            cnt.l-=1;
            cnt.r=a[cnt.l];
        }
        if(c[cnt.l]!=c[i]){
            ans+=q;
        }
        cnt.r-=q;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
