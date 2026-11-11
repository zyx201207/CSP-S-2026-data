#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,sizee=0;
    long long cn[200005];
    char st[200005];
    long long sf[200005][2];
    cin>>n;
    for(long long i=1;i<=n;i++){
        long long cnt;
        char aa;
        cin>>cnt>>aa;
        sf[i][0]=sizee;
        sizee+=cnt;
        cn[i]=cnt;
        st[i]=aa;
        sf[i][1]=sizee;


    }
    long long ans=0,l=1,e=n;;
    for(long long i=1;i<=sizee/2;i++){
        long long t,u;
            if(sf[l][0]<i&&sf[l][1]>=i){
                t=l;

            }else{
            l++;
            t=l;
            }
            if(sf[e][0]<sizee-i+1&&sf[e][1]>=sizee-i+1){
                u=e;

            }else{
            e--;
            u=e;
            }
        if(st[u]!=st[t]){
        ans++;
        }

    }
    cout<<ans;
    return 0;
}