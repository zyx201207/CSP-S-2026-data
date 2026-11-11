//GZ-J00606 遵义市新浦中学 张博浩文
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	  string n,i,o;
	  int m[]={0};
	  char g,a[]={0};
	  int b,s,k,l,qw=0;ba=0;
	  cin>>b;
	  for(int i=0;i<b;i++){
	  	cin>>b>>g;
	  	m[i]=b;
	  	a[i]=g;
	  }
	for(int i=0;i<b;i++){
		n=m[i]*a[i];
	}
	 s=n.size();
	 	if(s%2==1){
	 		k=(s-1)/2;
	 		for(int j=k-1;j>=0;j--){
	 			i=n[j];
			 } 
			 for(int i=0;i<k;i++){
			 	l=n[i];
			 }
			  for(int e=0;e<k;e++){
			  	if(i[e]!=l[e]){
			  		qw++;
				  }
			  	cout<<qw;
			  }
		 }else{
		 	l=s/2;
		 for(int x=l-1;x>=0;x--){
	 			i=n[x];
			 } 
			 for(int u=0;u<l;i++){
			 	l=n[u];
			 }
			  for(int e=0;e<l;e++){
			  	if(i[e]!=l[e]){
			  		ba++;
				  }
				  cout<<ba;
		 }
	
	return 0;
}
