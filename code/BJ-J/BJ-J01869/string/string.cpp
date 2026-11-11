#include<bits/stdc++.h>
using namespace std;

long long a[200010];
char c[200010];

int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    long long n,len=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        len+=a[i];
    }
    long long i=1,j=n,ans=0;
    while(i<=j){
        long long ma=min(a[i],a[j]);
        a[i]-=ma;
        a[j]-=ma;
        if(c[i]!=c[j]){
            ans+=ma;
        }
        if(a[i]==0){
            i++;
        }
        if(a[j]==0){
            j--;
        }
        if(i>=j){
            break;
        }
    }
    cout<<ans<<endl;

    return 0;
}
