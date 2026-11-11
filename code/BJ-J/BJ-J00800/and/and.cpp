#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,m,a[N],cnt,ans;
bool bj[N];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++) bj[i]=1;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    for(int w=1<<30;w>=1;w/=2){
        cnt=0;
        for(int i = 1;i<=n;i++){
            if(bj[i]&&(a[i]&w)!=0) cnt++;
        }
        if(cnt>=m){
            for(int i = 1;i<=n;i++){
                if((a[i]&w)==0) bj[i]=0;
            }
        }
    }
    ans=INT_MAX;
    for(int i = 1;i<=n;i++){
        if(bj[i]) ans&=a[i];
    }
    cout<<ans;

    return 0;
}
