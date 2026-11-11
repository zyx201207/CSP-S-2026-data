#include<iostream>
using namespace std;
#define int long long

int a[200001];
char c[200001];

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,tot=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        tot+=a[i];
    }
    int fst=1,lst=tot,l=1,r=n;
    while(l<r){
        if(c[l]!=c[r]){
            ans+=min(a[l],a[r]);
        }
        if(a[l]==a[r])r--,l++;
        else if(a[l]<a[r])a[r]-=a[l],l++;
        else a[l]-=a[r],r--;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
