#include <bits/stdc++.h>
using namespace std;
int n,a[200001];
long long ans;
char c[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    for(int i=1,j=n;i<=j;){
        if(c[i]!=c[j]){
            ans+=min(a[i],a[j]);
        }
        if(a[i]>a[j])
            a[i]-=a[j],j--;
        else if(a[j]>a[i])
                a[j]-=a[i],i++;
            else if(a[i]==a[j]) i++,j--;
    }
    cout<<ans;
    return 0;
}
