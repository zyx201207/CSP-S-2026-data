#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

const long long MAXN=5e5+10;
long long a[MAXN];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;

    for(long long i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a,a+n);

    long long cnt=0,i=1,j=0,ans=-1;
    while(cnt<=m&&i<n){
        cnt+=i*(a[i]-a[i-1]);
        i++;
    }
    if(i==n&&cnt<=m){
        cout<<n;
        return 0;
    }else{
        i--;
        cnt-=i*(a[i]-a[i-1]);
    }

    ans=i;
    while(i<n){
        cnt+=(i-j)*(a[i]-a[i-1]);
        i++;
        while(cnt>m){
            cnt-=a[i-1]-a[j];
            j++;
        }
        ans=max(ans,i-j);
    }

    cout<<ans;

    return 0;
}
