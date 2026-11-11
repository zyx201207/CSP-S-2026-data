#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
char c[N];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","s",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    long long sum1=0,sum2=0;
    int l=1,r=n;
    while(l<r){
        if(c[l]!=c[r]){
            ans+=min(a[l]-sum1,a[r]-sum2);
        }
        int x=min(a[l]-sum1,a[r]-sum2);
        sum1+=x;
        sum2+=x;
        if(sum1>=a[l]){
            sum1-=a[l];
            l++;
        }
        if(sum2>=a[r]){
            sum2-=a[r];
            r--;
        }
    }
    cout<<ans;
    return 0;
}
