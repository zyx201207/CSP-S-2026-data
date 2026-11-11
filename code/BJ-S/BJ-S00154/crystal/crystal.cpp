#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m;
long long a[N];
long long s;
int ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1,j=1;i<=n;i++){
        s=s+(i-j)*(a[i]-a[i-1]);
        while(s>m&&j<i){
            s-=a[i]-a[j];
            j++;
        }
        ans=max(ans,i-j+1);

    }
    cout<<ans<<endl;
    return 0;
}
