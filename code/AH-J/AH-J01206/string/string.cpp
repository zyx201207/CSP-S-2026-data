#include<bits/stdc++.h>
using namespace std;
long long int n,x,cnt=0,sum=0;
string b;
char a;
int main(){
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  cin>>n;
  for(int i=0;i<n;i++){
	  cin>>x>>a;
	  for(int j=0;j<x;j++){
		  b[cnt+j]=a;
	  }
	  cnt+=x;
  }
  for(int i=0;i<cnt/2;i++){
	  if(b[i]!=b[cnt-i])sum++;
  }
  cout<<sum;
  return 0;
}
