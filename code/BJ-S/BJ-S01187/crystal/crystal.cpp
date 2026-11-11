#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500009];
long long b[500009];
long long cnt=0,ans=1,anss=-1e6;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    long long ls=0,lss=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    sort(a+1,a+n+1);
    ls=a[2]-a[1];
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=ls){
            lss++;
            break;
        }
    }
    if(!lss){
        for(int i=1;i<=n;i++){
            int ypl= ((1+i)*i)/2;
            if(ls*ypl<=m){
                ans++;
            }

        }
        cout<<ans;
        return 0;
    }else{
        for(int i=1;i<=n;i++){
            b[i]=a[i]-a[i-1];
        }
        b[1]=0;
        for(int i=0;i<n;i++){
            ans=1;
            for(int j=2+i;j<=n;j++){
                if(cnt+(b[j]*(j-1+i))<=m){
                    ans++;
                    cnt=cnt+(b[j]*(j-1+i));
                }else{
                    break;
                }
            }
            anss=max(ans,anss);
        }

    }
    cout<<anss;
    return 0;
}
