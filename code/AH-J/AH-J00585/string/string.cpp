#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll l,n,a[200005],l2,ans;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        l+=a[i];
    }
    l2=l;
    l/=2;
    ll pos,num;
    for(int i=1;i<=n;i++){
        if(a[i]>l){
            pos=i;
            num=l;
            break;
        }else{
            l-=a[i];
        }
    }
    reverse(a+pos+1,a+n+1);
    reverse(c+pos+1,c+n+1);
    a[++n]=a[pos]-l-(l2%2);
    c[n]=c[pos];
    a[pos]=l;
    ll pos2=pos+1;
    for(int i=1;i<=pos;i++){
        while(a[i]>=a[pos2]&&pos2<=n){
            if(c[i]!=c[pos2])ans+=a[pos2];
            a[i]-=a[pos2];
            pos2++;
        }
        if(a[i]<a[pos2]){
            if(c[i]!=c[pos2])ans+=a[i];
            a[pos2]-=a[i];
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}


