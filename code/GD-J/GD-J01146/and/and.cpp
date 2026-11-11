#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
    int a[220000]={};
	int n,m;
	int ans=1;
	int k;
	int mx=-1;	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		mx=-1;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		ans=mx;
		cout<<mx;
		
	}
	else if(m==2){
			
		mx=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,(a[i]&a[j]));
			}
		}
		ans=mx;
		cout<<mx;
			
	}
	else if(m==n){
		
		int k=a[1];
		for(int i=2;i<=n;i++) k=(k&a[i]);
		ans=k;
		cout<<ans;
	
	}
	return 0;
} 

