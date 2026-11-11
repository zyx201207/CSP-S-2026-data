#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+7;

ll cnt,p[N];
char c[N];
bool f=0;
ll ans=0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        cin>>c[i];
        cnt+=p[i];
    }
    int l=1,r=n;
    while(l<r){
        if(c[l]!=c[r]){
            if(p[l]==p[r]){
                ans+=p[l];
                p[l]=0;
                p[r]=0;
            //    l++;r--;
            }
            else if(p[l]>p[r]){
                ans+=p[r];
                p[l]-=p[r];
                p[r]=0;

            //    r--;
            } else if(p[l]<p[r]){
                ans+=p[l];
                p[r]-=p[l];
                p[l]=0;

             //   l++;
            }
        }else{
            ll mn=min(p[l],p[r]);
            p[l]-=mn;
            p[r]-=mn;
        }
        if(p[l]==0) l++;
        if(p[r]==0) r--;

    }
    cout<<ans;
}
