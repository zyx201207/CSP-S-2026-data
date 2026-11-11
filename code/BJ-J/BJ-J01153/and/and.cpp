#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int a[N],b[N];
 int n,m;
int sum;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
  cin>>n>>m;
  int cnt=INT_MIN;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    b[i]=a[i];
    while(b[i]%2==0){
           b[i]/=2;
    }
  }
  sort(a+1,a+n+1);
 if(m==1){
    cout<<a[n];
    return 0;
 }
 if(m==n){
        int cnt=a[1];
    for(int i=2;i<=n;i++){
        cnt=cnt&a[i];
    }
    bool f=1;
    for(int i=1;i<=n;i++){
        if(b[i]==1)f=0;
    }
if(f==1){
        cout<<a[n-1];
        return 0;
    }
if(m==2){
        for(int i=1;i<=n-m;i++){
            for(int j=i+1;j<=n;j++){
                cnt=max(cnt,a[i]&a[j]);
            }
        }
    }
 cout<<cnt<<endl;
 }
    return 0;
}



