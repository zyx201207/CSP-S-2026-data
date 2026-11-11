#include<bits/stdc++.h>
using namespace std;
int a[99999],b[99999],ans=0;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)	
		for(int i=1;i<=n;i++){
			if(m>0){
				if(a[n/2+1]>a[i]){
					a[i]++;
					m--;
				}
				else if(a[i]<a[i]){
					m--;
				}}
			}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i/2+1]){
			ans++;
		}
	}
	cout<<ans; 
}
	
