
#include<bits/stdc++.h>
using namespace std;
int n,m,t=0;
int main(){
  freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m;
  int a[n],b[n]={0},c[m]={0};
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=1;i<=n;i++){
    for(int j=0;j<t;j++){
      if(a[i]==b[j]){
        for(int x=j;x<t;x++) b[x]=0;
        b[j]=a[i];
        t=j+1;
      }else{
        b[t++]=a[i];
      }
    }
    for(int j=1;j<=n;j++){
      c[j-1]++;
      b[j]=0;
    }
  }
  for(int i=0;i<m;i++) cout<<c[i];
  fclose(stdin);
  fclose(stdout);
  return 0;
}
