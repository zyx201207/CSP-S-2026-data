#include<bits/stdc++.h>
using namespace std;
int a[200000],b[200000][32]={-1},k[2000000]={1},ma=0,z=0,t=0,h=0;
int n,m;
void e(int d,int i){
  while(d){
    b[i][t++]=d%2;
    d/=2;
  }
  return;
}
int main(){
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>a[i];
    e(a[i],i);
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n&&k[j]!=0;j++){
      if(b[i][j]==0) k[j]=-1;
    }
    int c=0;
    for(int j=0;j<n&&k[j]!=0;j++){
      c++;
    }
    if(c<m){
       for(int j=0;j<n&&k[j]!=0;j++) h+=a[i];
       for(int j=0;j<n&&k[j]==-1;j++){
         ma=max(ma,a[j]);
       }
       cout<<h+ma;
    }
    if(c==m){
       for(int j=0;j<n&&k[j]!=0;j++) h+=a[i];
       cout<<h;
    }
     for(int j=0;j<n&&k[j]==-1;j++){
      k[j]=0;
     }
  }
  fclose(stdin);
  fclose(stdout);
  return 0;
}
