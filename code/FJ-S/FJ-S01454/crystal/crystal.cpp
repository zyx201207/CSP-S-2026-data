#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
	int z=0; 
	int q,w,e;
	int m;
	int n;
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		if(a[i]>a[j]){
    			q=a[i];
    			a[i]=a[j];
    			a[j]=q;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int w=9;
     a[i]=w-a[i];
 }
    if(e<=m){
    	int i=1;
 	e=a[i+1]+e;
 	z++;
}else{
 cout<<z-1;
}
      return 0;
}
