#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int s=0,b=0,t=0;
  long long n=0;
  cin>>n;
  char c=0,a[n*1000000000]={0};
  for(int i=0;i<n;i++){
    cin>>b>>c;
    for(int j=0;j<c;j++){
      a[t++]=c;
    }
  }
  for(int i=0;i<t/2;i++){
    if(a[i]!=a[t-1-i]) s++;
  }
  cout<<s;
  fclose(stdin);
  fclose(stdout);
  return 0;
}
