#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010;
int a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,ans=0;
    bool flag=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n&&flag;i++){
        for(int j=1;j<=i;j++){
            int c=a[i]-a[j];
            m-=c;
            a[j]=a[i];
            if(m<0){
                flag=0;
                break;
            }
        }
        if(flag==0){
            break;
        }
        ans=i;
    }
    cout<<ans<<"\n";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
