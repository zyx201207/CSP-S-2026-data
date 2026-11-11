#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  long long n,m,p,num=0,ks=0;
  cin>>n>>m;
  long long a[n],c[n];
  for(int i=1;i<=n;i++){
    cin>>a[i];
    num+=a[i];
  }
  p=num/n;
  sort(a+1,a+n+1);
  for(int i=1;i<=n;i++){
      c[i]=a[i]-p;
  }
  for(int i=1;i<=n;i++){
    while(m>0){
      if(c[i]<0){
	a[i]++;
	c[i]++;
      }
      else if(c[i]>0){
	a[i]--;
	c[i]--;
      }
      m--;
    }
  }
  for(int i=1;i<=n;i++){
    if(a[i]==p){
      ks++;
    }
  }
  cout<<ks;
  return 0;
}
