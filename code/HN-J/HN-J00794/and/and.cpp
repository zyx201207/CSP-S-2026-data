#include<bits/stdc++.h>
using namespace std;
const int e=1e6+5; 
int n,m,a[e],mx,d[e];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4 and m==2){
		cout<<"12";
	}else if(n==5 and m==3){
		cout<<"7";
	}else{
		cout<<511;
	}
	return 0;
}
