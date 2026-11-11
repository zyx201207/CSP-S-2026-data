#include<bits/stdc++.h>
using namespace std;
const int N=5e5+8;
int n;
long long ls[N],m,ans=1,a[N];
int main(){
    freopen("crystal","r",stdin);
    freopen("crystal","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int mid=0;
    if(n%2==0) mid=n/2;
    else mid=(n+1)/2;
    ls[mid]=1e18;
    for(int i=1;i<=n;i++){
        if(i<mid){
            ls[i]=a[mid]-a[i];
        }
        else(i>mid){
            ls[i]=a[i]-a[mid];
        }
    }
    sort(ls+1,ls+1+n);
    for(int i=1;i<=n;i++){
        if(m>0&&ls[i]<=m){
            m-=ls[i];
            ans++;
        }
        else break;
    }
    cout<<ans;
        return 0;
    }

