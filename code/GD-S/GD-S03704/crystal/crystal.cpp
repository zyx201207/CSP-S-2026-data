#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int w,n,ans=0;
	int m;
	cin>>m>>n;
	int a[m+2],b[m+2];
	
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=m-1;i++){
			if(a[i]>a[i+1]){
				swap(a[i],a[i+1]);
			}
		}
	} 
	for(int i=1;i<=m-1;i++){
		b[i]=a[i+1]-a[i];
	}
	for(int j=1;j<=m-1;j++){
		for(int i=1;i<=m-2;i++){
			if(b[i]>b[i+1]){
				swap(b[i],b[i+1]);
			}
		}
	}
	w=0;
	for(int i=1;i<=m-1;i++){
		w+=b[i];
		if(w<=n)ans++;
	}
	if(b[1]<=n){
		cout<<ans;
	}
	else{
		cout<<"1";
	}
	return 0;
}

 
