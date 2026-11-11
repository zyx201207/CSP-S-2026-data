#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005],End[200005];
char s[200005];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ll sum=0,ans=0;
    int n;
    cin>>n;
    End[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
        End[i]=End[i-1]+a[i];
        sum+=a[i];
    }
    ll kl=1,kr=n,suml=1,sumr=sum;
    ll midl,midr;
    if(sum%2==0){
        midl=sum/2;
        midr=sum/2+1;
    }
    else{
        midl=sum/2;
        midr=sum/2+2;
    }
   // cout<<min(midl,End[kl])-suml+1<<" "<<sumr-max(End[kr-1]+1,midr)+1<<" "<<ans<<'\n';
    for(ll l=1,r=sum;suml<sumr;){

        if(min(midl,End[kl])-suml+1<sumr-max(End[kr-1]+1,midr)+1){
           //cout<<">"<<1<<"<";
            if(s[kl]!=s[kr]){
                ans+=min(midl,End[kl])-suml+1;
            }
            sumr-=End[kl]-suml+1;
            suml=End[kl]+1;
            kl++;
        }
        else if(min(midl,End[kl])-suml+1>sumr-max(End[kr-1]+1,midr)+1){
          // cout<<">"<<2<<"<";
            if(s[kl]!=s[kr]){
                ans+=sumr-max(End[kr-1]+1,midr)+1;
            }
            suml+=sumr-max(End[kr-1]+1,midr)+1;
            sumr=End[kr-1];
            kr--;
        }
        else if(min(midl,End[kl])-suml+1==sumr-max(End[kr-1]+1,midr)+1){
           // cout<<">"<<3<<"<";
            if(s[kl]!=s[kr]){
                ans+=min(midl,End[kl])-suml+1;
            }
            sumr=End[kr-1];
            suml=End[kl]+1;
            kl++;
            kr--;
        }
       // cout<<min(midl,End[kl])-suml+1<<" "<<sumr-max(End[kr-1]+1,midr)+1<<" "<<ans<<'\n';
    }
    //cout<<'\n';
    cout<<ans;
    //*/
    return 0;
}
