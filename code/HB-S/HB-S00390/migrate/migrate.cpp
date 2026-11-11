#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,N,d;
long long x[2000005],a[30],n_a=0;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        n_a++;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        long long mid=(x[n]-x[1])/2;
        if(d>mid) a[n_a]=0;
        else{
            long long cha=x[2]-x[1],cnt=0;
            for(int i=1;i<n;i++){
                if(x[i+1]-x[i]!=cha) cnt=1;
            }
            if(cnt==0) a[n_a]=n-4+1;
            else a[n_a]=0;
        }
    }
    for(int i=1;i<=t;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}

