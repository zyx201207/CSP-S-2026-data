#include<bits/stdc++.h>
using namespace std;
int a[1008];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k,efen;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		a1 3  a2 15  a3 12  a4 12
		if(a[1]<a[2]){
			a[2]=a[1];
		}
		if(a[2]<a[3]){
			a[3]=a[2];
		}
		if(a[3]<a[4]){
			a[4]=a[3];
		} 
	}
	
	if(n%2==1){
		efen=n/2+1;
	}
	if(n%2==0){
		efen=n/2;
	}
	cout<<a[efen]<<endl;
}
