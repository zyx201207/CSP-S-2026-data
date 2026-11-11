#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
  int n,m;
  cin>>n>>m;
  int a[n];
  while(n--){
  	int b;
  	cin>>b;
  	for(int i=n;i>0;i--){
  	  if(a[i]=b){ 
  	  	for(int j=i;j>0;j--){
  	  	  a[j]=0;	
		}
      }
	}
  	a[n]=b;
  }
  for(int i=m;i>0;i--){
  	if(a[i]==0){
  	  continue;	
	}else{
	  cout<<a[i]<<" ";	
	}
  }
  return 0;
}

