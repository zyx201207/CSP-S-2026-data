#include <bits/stdc++.h> 
using namespace std;
string a;
int la,cnt,n,m;
char b;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m>>b;
		for(int j=0;j<m;j++){
			a[j]=b;
			
		}
		
	}
	la=a.size();
	int la1=la/2;
	for(int i=0;i<la1;i++){
	  for(int j=la1-1;j>0;j--){
	  	 if(a[i] !=a[j]){
	  	 	 a[j]=a[i];
	  	 	 cnt++;
		   } 
	  }	
	}
	cout<<cnt;
	return 0;
}
