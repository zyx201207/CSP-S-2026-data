#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[1000]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int x=1,y=0,z=1;
	for(int j=1;j<=m;j++){
		for(int i=z;i<=n;i++){
		if(a[i]<a[i+1]){
			while(a[i]<a[i+1]){
				y++;
				a[i]+=1;
			}
		}
		
}
	j=j+y-1;
	z++;
	}
	
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			z++;
		} 
	}
	cout<<z;
	return 0;
} 
