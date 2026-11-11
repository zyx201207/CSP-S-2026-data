#include <bits/stdc++.h>
using namespace std;
long long a=0,b=0;
long long aa[500005]={};
long long ab[500005]={};
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>a>>b;
    for(long long i=0;i!=a;i++){
        cin>>aa[i];
    }
    sort(aa,aa+a);
    ab[0]=0;
    for(long long i=1;i!=a;i++){
        ab[i]=ab[i-1]+(aa[i]-aa[i-1])*i;
    }
    long long l=0,r=0,ans=0;
    while(r!=a){
        if(ab[r]-ab[l]-l*(aa[r]-aa[l])<=b){
            ans=max(ans,r-l);
        }
        else{
            while(ab[r]-ab[l]-l*(aa[r]-aa[l])>b)l++;
            ans=max(ans,r-l);
        }
        r++;
    }
    cout<<ans+1;
    return 0;
}
