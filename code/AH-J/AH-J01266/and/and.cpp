#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int t[10];
bool cf(long long a){
    int s=a+1;
    while(s){
        if(s==1){
            break;
        }
        if(s%2==1){
            return 0;
        }
        s/=2;
    }
    return 1;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    long long n,m,f1=1,maxx=0;
    long long sum;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1){
            sum=a[i];
        }else{
            sum=(sum&a[i]);
        }
        if(cf(a[i])==0){
            f1=0;
        }
        maxx=max(maxx,a[i]);
    }
    if(m==1){
        cout<<maxx;
    }else if(m==2){
        long long maxx1=0;
        for(int i=1;i<n;i++){
            for(int j=1;j<i;j++){
                maxx1=max(maxx1,a[i]&a[j]);
            }
        }
        cout<<maxx1;
    }else if(m==n-1){
        long long maxx1=0;
        for(int i=1;i<=n;i++){
            maxx1=max(maxx1,sum&a[i]);
        }
        cout<<maxx1;
    }else if(m==n){
        cout<<sum;
    }else if(f1){
        sort(a+1,a+1+n);
        cout<<a[n-m+1];
    }else if(maxx<4){
        for(int i=1;i<=n;i++){
            t[a[i]]++;
        }
        if(m<=t[3]){
            cout<<3;
            return 0;
        }
        m-=t[3];
        if(m<=t[2]){
            cout<<2;
            return 0;
        }
        m-=t[2];
        if(m<=t[1]){
            cout<<1;
            return 0;
        }
        cout<<0;
    }else{
        sort(a+1,a+1+n);
        long long ans=a[n];
        for(int i=n-1;i>=n-m+1;i--){
            ans=ans&a[i];
        }
        cout<<ans;
    }
    return 0;
}
