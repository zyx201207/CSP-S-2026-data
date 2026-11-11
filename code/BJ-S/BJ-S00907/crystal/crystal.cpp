

#include<bits/stdc++.h>
using namespace std;
long long n;
long long m,san=0;
long long a[100003];
void panduan(long long d){
    if(d<1){
        return;
    }
    long long sum=0,s=0;
    for(int i=1;i<=n;i++){
        if(i!=d&&a[d]>=a[i]){
            sum+=a[d]-a[i];
            s++;
        }
        continue;
    }
    if(sum<=m&&(s+1)>san){
        san=(s+1);
        panduan(d-1);
    }
    else{
        panduan(d-1);
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    panduan(n);
    cout<<san;
    return 0;
}
