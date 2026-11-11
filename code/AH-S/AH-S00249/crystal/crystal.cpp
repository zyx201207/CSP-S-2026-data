#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,m;
int v(long long x)
{
    long long an=a[x],m1=m;
    int ans=0;
    bool f=false;

    for(int i=x;i>=0;i--){
        //if(f==false&&a[i]==an) f=true;
        //if(f){
        if(m1>=(an-a[i])){
            m1-=(an-a[i]);
            ans++;
            //cout<<m1<<endl;
        }else{
            break;
        }
        //}
    }
    return ans;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(n==1){
        cout<<1<<endl;
    }
    int ans=1;

    int fr=0,now=1;
    long long u=0;
    for(int i=1;i<n;i++){
        u=u+(i-fr)*(a[i]-a[i-1]);
        //cout<<u<<endl;
        if(u>m){
            while(u>m&&fr<i){
                u=u-(a[i]-a[fr]);
                fr++;
                now--;
            }
        }
        now++;
        ans=max(ans,now);
    }
    /*
    for(int i=0;i<n;i++){
        ans=max(ans,v(i));
    }

    */
    cout<<ans<<endl;
    return 0;
}
