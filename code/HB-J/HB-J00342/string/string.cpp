#include<bits/stdc++.h>
using namespace std;
int n,a[200005],i,j;
char c[200005];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i]>>c[i];
    i=1,j=n;
    while(i<j){
        if(a[i]==a[j]){
            if(c[i]!=c[j])ans+=a[i];
            i++,j--;
        }else if(a[i]>a[j]){
            if(c[i]!=c[j])ans+=a[j];
            a[i]-=a[j],j--;
        }else{
            if(c[i]!=c[j])ans+=a[i];
            a[j]-=a[i],i++;
        }
    }
    cout<<ans;
    return 0;
}
