#include<bits/stdc++.h>
using namespace std;
long long a[500010];
long long s[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    bool f=false;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        for(int j=n;j>=i;j--){
            s[i]+=a[n]-a[j];
        }
    }
    for(int i=n-1;i>1;i--){
        if(a[i+1]-a[i]!=a[i]-a[i-1]){
            f=true;
        }
    }
    if(f==false){
        int ss=0;
        for(int i=1;i<=n;i++){
            ss+=i*(a[2]-a[1]);
            if(ss>m){
                cout<<i<<endl;
                return 0;
            }if(ss==m){
                cout<<i+1<<endl;
                return 0;
            }
        }
    }
    long long sum=-1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(s[i]-s[j]*(j-i+1)+s[j+1]*(j-i)<=m){
                if(j-i+1>=sum){
                    sum=j-i+1;
                }
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}

