#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+5];
    int b[n+5];
    int x[m+5];
    int cnt;
    int i;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        int c=a[i];
        int w=30;
        int cnt=0;
        while(c>=0&&w>=0){
            if(c>=pow(2,w)){
                cnt++;
                c-=pow(2,w);
            }
            else{
                w--;
            }
        }
        b[i]=cnt;
    }
    for(int i=1;i<=m;i++){
        int maxx=0;
        int mw=0;
        for(int j=1;j<=n;j++){
            if(b[j]>=maxx){
                maxx=b[j];
                mw=j;
            }
        }
        x[i]=a[mw];
        b[mw]=0;
    }
    int sum=x[1];
    for(int i=2;i<=m;i++){
        sum&=x[i];
    }
    cout<<sum;
    return 0;
}
