#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  int n,m,a,b;
  char x,y;
  cin>>n;
  cin>>a>>x;
  cin>>m;
  cin>>b>>y;
  if(n==m){
	cout<<1;
  }else{
	cout<<0<<0<<0<<0;
	return 0;
  }if(a==b){
	cout<<1;
  }else{
	cout<<0<<0<<0;
	return 0;
  }cout<<!;
  if((x==y+1 || x==y-1) && (x=='C' && y=='D' || y=='C' && x=='D')){
	cout<<1;
  }else{
	cout<<0;
   }return 0;
}
