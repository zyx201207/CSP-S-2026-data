#include<bits/stdc++.h>
using namespace std;
int in[100005];
int main(){
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  int n;
  long long count=0;
  string s1,s2;
  cin>>n;
  for(int i=0,j=n;i<n,j>0;i++,j--){
  	char c;
  	int a;
  	cin>>a>>c;
  	s1[i]=c;
  	s2[j]=c;
  	in[i]=a;
  }
  for(int i=0;i<n;i++){
  	if(s1[i]!=s2[i]){
  	  count+=in[i];	
	}
  }
  cout<<count/2;
  return 0;
}

