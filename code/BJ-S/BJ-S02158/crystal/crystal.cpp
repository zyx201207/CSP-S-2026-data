#include<bits/stdc++.h>
using namespace std;
long long a[100010],sa[100010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,m;
    cin>>n>>m;
    sa[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sa[i]=sa[i-1]+a[i];
    }
    int lastpos=0,firstpos=0;
    int cnt=0;
    for(int i=n;i>=1;i--){
        for(int j=1;j<i;j++){
            if(abs((i-j)*a[i]-(sa[i-1]-sa[j-1]))<=m){
                lastpos=j;
                firstpos=i;
                break;
            }
        }
        cnt=max(cnt,firstpos-lastpos+1);
    }
    cout<<cnt;
    return 0;
}
