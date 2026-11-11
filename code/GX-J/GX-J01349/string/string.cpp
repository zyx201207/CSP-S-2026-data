#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int r;
	cin>>r;
	string a;
	for(int j=0;j<r;j++){
		long long e;
		char t;
		cin>>e>>t;
		for(int i=0;i<e;i++){
			a+=t;
			}
		} 
    long long cnt=0,l=0,y=a.size()-1;
      while(l<y){
		  if(a[l]!=a[y]){
			  cnt++;
			  }
			 l++;
			 y--;
		  }
		  cout<<cnt;
	return 0;
	}
//miao~miao~miao~
