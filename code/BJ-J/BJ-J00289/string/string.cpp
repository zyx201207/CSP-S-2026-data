#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
int n;
ll a[N],ans;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        cin>>c[i];
    }
    int l=1,r=n;
    while(l<r){
        if(a[l]<a[r]){
            if(c[l]!=c[r])ans+=a[l];
            a[r]-=a[l++];
        }
        else if(a[r]<a[l]){
            if(c[l]!=c[r])ans+=a[r];
            a[l]-=a[r--];
        }
        else{
            if(c[l]!=c[r])ans+=a[l];
            l++,r--;
        }
        //printf("%d %d %lld\n",l,r,ans);
    }
    printf("%lld\n",ans);
    return 0;
}
