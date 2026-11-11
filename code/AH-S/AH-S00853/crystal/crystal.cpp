#include<bits/stdc++.h>
using namespace std;
int n,maxc=1;
long long m,spd,a[500005],cha[500005];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++) cha[i]=a[i]-a[i-1];
    if(a[1]==a[n]) cout<<n;
    else{
        for(int i=1;i<=n;i++){
            spd=0;
            for(int j=i+1;j<=n;j++){
                spd+=cha[j]*(j-i);
                if(spd>m||j==n){
                    maxc=max(maxc,j-i);
                    break;
                }
            }
        }
        cout<<maxc;
    }
    return 0;
}
