#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long ans;
int last;
int n,a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cin>>c[i];
    }
    for(int i=1;i<n;i++){
        a[n]-=last;
        last=0;
        while(a[i]>=a[n]&&i<n){
            if(c[i]!=c[n]) ans+=a[n];
            a[i]-=a[n];
            n--;
        }
        if(c[i]!=c[n]) ans+=a[i];
        last=a[i];
    }
    printf("%lld",ans);
    return 0;
}

