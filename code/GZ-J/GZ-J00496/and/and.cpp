//GZ-J00496 遵义市第十六中学 张旋彬
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,cnt=0,maxn=0,arr[100001];
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n-1;j++){
           cnt=i&j;
           if(cnt>maxn) maxn=cnt;
        }
    }
    cout<<maxn;
    return 0;
}
