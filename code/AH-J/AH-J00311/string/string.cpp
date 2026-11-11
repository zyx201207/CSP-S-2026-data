#include<iostream>
using namespace std;
long long n,k,ans;
struct stu{
    long long ab;
    char id;
}a[200005];
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&k);
        cin>>c;
        a[i].id=c,a[i].ab=k;
    }
    int l=1,r=n;
    while(l<=r){
        if(a[l].id!=a[r].id&&a[l].ab==a[r].ab) ans+=a[r].ab;
        if(a[l].id!=a[r].id&&a[l].ab!=a[r].ab) ans+=max(a[l].ab,a[r].ab);
        l++,r--;
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
