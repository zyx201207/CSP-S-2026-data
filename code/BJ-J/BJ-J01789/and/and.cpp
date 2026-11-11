#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,a[N],mmax=-1,f,t,ans;
set<int> st;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    a[0]=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==a[i-1]) t++;
        else t=1;
        if(t>mmax){
            mmax=t;
            f=a[i];
        }

    }
    if(mmax>=m){
        cout<<f;
        return 0;
    }
    else{
        sort(a+1,a+1+n,cmp);
        m-=mmax;
        ans=f;
        for(int i=1;i<=n&&m>0;i++){
            if(a[i]!=f){
                ans&=a[i];
                m--;
            }
        }
    }
    cout<<ans;
    return 0;
}


