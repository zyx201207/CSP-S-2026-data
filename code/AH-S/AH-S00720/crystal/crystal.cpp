#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,ans=0,pos=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=1000000000000;
    }
    sort(a,a+n);
    for(int i=n;i>=1;i--){
        long long he=0;
        int cnt=1;
        for(int j=i-1;j>=1;j--){
            he+=a[i]-a[j];
            cnt++;
            if(he>m){
                cnt--;
                if(ans<cnt){
                    ans=cnt;
                }
                break;
            }
            if(he==m){
                if(ans<cnt){
                    ans=cnt;
                }
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
