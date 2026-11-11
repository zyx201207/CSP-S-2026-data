#include<bits/stdc++.h>
using namespace std;
int long long a[500005];
int long long d[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdin);
    int n;
    int long long m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=0;i<=n+5;i++){
        d[i]=1;
    }
    for(int i=2;i<=n;i++){
        int x=m;
        for(int j=i-1;j>=1;j--){
                int y=a[j];
           while(y!=a[i]){
                y+=1;
                x-=1;
           }
          if(x<0){
               continue;
          }
          d[i]+=1;

        }
    }
    sort(d,d+n+1);
    cout<<d[n];
    return 0;
}