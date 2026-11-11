#include<bits/stdc++.h>
using namespace std;
unsigned long long a[200005];
bool cmp(unsigned long long a,unsigned long long b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    unsigned long long ans;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    ans=a[0];
    for(int i=1;i<m;i++){
        ans=ans&a[i];
    }
    int k=1;
    while(ans==0){
        ans=a[k];
        for(int i=k+1;i<m+k;i++){
            ans=ans&a[i];
        }
        k++;
    }
    cout<<ans;
    return 0;
}