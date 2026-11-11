#include<bits/stdc++.h>
using namespace std;
long long a[200000],s[100000];
int main(){	
  freopen("and.in","r",stdin);
  freopen("and.out","w",stdout);
  int n=0,m=0,k=0;
  cin>>n>>m;
  for(int i=0;i<n;i++){
  	scanf("%d",a[i]);
  	while(a[i]>0){
  		s[i]=a[i]%2;
  		k++;
  		a[i]/2;
	  }
  }
  for(int j=k;j>=0;j--)
  cout<<s[j]<<endl;
return 0;
}
