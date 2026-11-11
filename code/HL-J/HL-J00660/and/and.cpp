#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,p=3,a[200007],maxs=0,agai;
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
      cin >> a[i];
    }
    for(int i = 1;i<=n;i++){
        for(int j =i+1;j<=n;j++){
          if(a[i]&a[j]>maxs){maxs=a[i]&a[j];}
      }
    }
    agai = maxs;
    while(p==m){
      for(int i =1;i<=n;i++){
        if(maxs<agai&a[i]){maxs=agai&a[i];}
      }
      agai=maxs;
    }
    cout << agai;
    return 0;
}
