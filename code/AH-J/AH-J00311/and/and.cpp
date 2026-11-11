#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[200005],ans,ans1,ans2,c=1,d=1,jm,om;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1,cmp);
    ans=a[1];
    for(int i=2;i<=m;i++){
        ans&=a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i]%2==1){
            if(c==1) ans1=a[i],jm=a[i],c++;
            else c++,ans1&=a[i];
            if(c==m+1) break;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]%2==0){
            if(d==1) ans2=a[i],om=a[i],d++;
            else d++,ans2&=a[i];
            if(d==m+1) break;
        }
    }
    if(c!=m) ans1=0;
    if(d!=m) ans2=0;
    if(m==2) cout<<max(ans,max(ans1,max(ans2,(jm&om))));
    else cout<<max(ans,max(ans1,ans2));
    fclose(stdin);
    fclose(stdout);
    return 0;
}
