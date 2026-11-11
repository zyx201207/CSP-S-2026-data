
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,ans=1;
long long a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long ansi=1,k=m,h=n;
    for(int i=n-1;i>=1;){
        long de=a[h]-a[i];
        if(k>=de){
            i--;
            ansi++;
            k-=de;
        }else{
            ans=max(ans,ansi);
            ansi--;
            h--;
            k=k+ansi*(a[h+1]-a[h]);
        }
    }
    ans=max(ans,ansi);
    cout<<ans;
    return 0;
}
