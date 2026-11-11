#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5]={0};
	for(int i=0;i<n;i++) cin>>a[i];
	int ab=-91;
	if(m==1){
		for(int i=0;i<n;i++) ab=max(ab,a[i]);
		cout<<ab;
		return 0;
	}
	if(m==2){
	 	for(int i=0;i<n;i++){
	 		for(int j=0;j<n;j++){
	 			if(i==j) continue;
	 			int a1=a[i],a2=a[j];
	 			ab=max(ab,int(a1&a2));
			 }
		 }
		 cout<<ab;
		 return 0;
	}
	if(m==n){
		ab=1;
		for(int i=0;i<n;i++) ab=int(ab&int(a[i]));
		cout<<ab;
		return 0;
	}
	cout<<0;
	return 0;
}
