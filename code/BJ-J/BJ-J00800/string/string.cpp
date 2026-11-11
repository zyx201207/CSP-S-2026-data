#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
char c[N];
int a[N],n,l,r,llast,rlast;
long long ans;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    l=1,r=n;
    llast=a[l],rlast=a[r];
    while(l<r){
        if(llast<=rlast){
            if(c[l]!=c[r]) ans=ans+llast;
            rlast-=llast;
            l++;
            llast=a[l];
        }else{
            if(c[l]!=c[r]) ans=ans+rlast;
            llast-=rlast;
            r--;
            rlast=a[r];
        }
    }
    cout<<ans;

    return 0;
}
