#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e7;
int n,m,c,d,cnt;
int a[N];
int b[N];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        if(a[i]==a[i-1])
                cnt++;
    }
    sort(a+n,a+n+1);
    c=a[n/2+1];


    if(m!=0){
    for(int i=n/2+1;i>=1;i--){
        if(a[i]!=c){
            d=c-a[i];
            m-=d;
            cnt++;
            }
        }
    }
    cout <<cnt+1 << endl;

    return 0;
}
