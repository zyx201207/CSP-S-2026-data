#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1001010],s[1000100];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i!=1){
            s[i]=s[i-1]+(a[i]-a[i-1])*i;
        }

        //cout<<s[i]<<endl;
    }
    s[1]=0;
    long long maxn=-1;
    for(int i=1;i<=n;i++){
        long long e=i;
        //cout<<s[i]-s[e-1]-(a[i]-a[e-1])*e<<endl;
        while(s[i]-s[e]-(a[i]-a[e])*e<=m&&e>0){
                //cout<<s[i]-s[e]-(a[i]-a[e])*e<<endl;
            //cout<<i<<" "<<e<<" "<<s[i]<<" "<<s[e]<<" "<<(a[i]-a[e])<<" "<<(e)<<" "<<s[i]-s[e]-(a[i]-a[e])*e<<endl;
            e--;
        }
        //cout<<i<<" "<<e<<endl;
        maxn=max(maxn,i-e);
    }
    cout<<maxn;
}
