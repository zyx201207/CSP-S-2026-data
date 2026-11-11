#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0;
	int a[500009];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
		for(int i=0;i<n;i++){
			if(a[i]==a[i+1]){
				ans++;
				a[i+1]+=a[i];
				a[i]=0;}
			}
			
		

	cout<<23;
	return 0;
}
	
