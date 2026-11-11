#include<bits/stdc++.h>
using namespace std;
int a[200005];
int pows[35]={2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
bool check(int x){
    for(int i=1;i<=30;i++){
        if(x==pows[i])return 0;
    }
    return 1;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    int cnt=0;
    long long sum;
    for(int i=1;i<=n;i++){
        if(cnt==m)break;
        if(!check(a[i]))continue;
        if(cnt==0){
            cnt++;
            sum=a[i];
            continue;
        }
        long long t=sum&a[i];
        if(!check(t))continue;
        cnt++;
        sum=t;
    }
    cout<<sum;
    return 0;
}
