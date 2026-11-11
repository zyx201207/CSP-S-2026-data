#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  int n,m[10000];
  char a[10000];
  cin>>n;
  for(int i=1;i<=n;i++){
	cin>>m[i]>>a[i];
  }if(n==1){
	cout<<0;
  }else{
  cout<<1;
  }
}
