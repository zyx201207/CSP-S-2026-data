#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500001],b[500001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int pos=a[i];
        int net=m;
        b[i]=1;
        for(int s=i+1;s<=n;s++){
            if(net>=a[s]-a[i]){
                net-=a[s]-a[i];
                b[i]++;
            }
            else{
                break;
            }
        }
    }
    long long maxn=-0x3f3f3f3f;
    for(int i=1;i<=n;i++) maxn=max(maxn,b[i]);
    cout<<maxn; 
    return 0;
}
