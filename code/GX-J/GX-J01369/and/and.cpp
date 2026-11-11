#include <bits/stdc++.h>
using namespace std;
int n=0,m=0,a[200001],c;
int d(a,c){
    for(int i=0;i<c;i++) a[i] and d(c-1);
    }

int main(){
    freopen("and1.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n;
    cin>>m;
    for(int i;i<=n;i++){
        cin>>a[i];
    }
  //  int cs[200001];
  //  for(int j=0;j<=m;j++){
 //       cs[j]=m and cyynb(j-1,a);
   // }
    sort(a,a+n);
    cout << a[0] and d(a,m);
    return 0;
}
