#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char c[200005];
long long sum=0,mid=0;
long long dd[200005];
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        dd[i]=dd[i-1]+a[i];
        sum+=a[i];
    }
    for(int i=n;i>=1;i--){
        if(dd[i]>(sum+1)/2)mid=i;
    }
    long long x=1,y=n;
    while(!(x==mid&&y==mid)){

        if(a[x]>a[y]){
            if(c[x]!=c[y])ans+=a[y];
            a[x]-=a[y];
            y--;
        }else if(a[y]>a[x]){
            if(c[x]!=c[y])ans+=a[x];

            a[y]-=a[x];
            x++;
        }else{
            if(c[x]!=c[y])ans+=a[x];
            x++;
            y--;
        }
        if(x>mid)x=mid;
        if(y<mid)y=mid;
        //cout<<x<<' '<<y<<' '<<ans<<'\n';
    }
    cout<<ans;
    return 0;
}
