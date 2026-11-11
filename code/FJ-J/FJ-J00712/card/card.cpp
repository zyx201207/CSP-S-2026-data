#include<bits/stdc++.h>
using namespace std;
int a[200010],ans[200010]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		if(a[1]==a[n]){
			ans[a[n]]=n;
			ans[m+1-a[n]]=0;
			cout<<ans[1]<<" "<<ans[2];
		}
		else{
			int k=m+1-a[n];
			int g;
			ans[a[n]]=n; 
			for(int i=1;i<=n-1;i++){
				if(a[i]==k){
					g=i;	
				}
			}
			ans[k]=g;
			cout<<ans[1]<<" "<<ans[2];
		}
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	a[n+1]=-1;
	for(int i=2;i<=n+1;i++){
		if(a[i]!=a[i-1]){
			cout<<i-1<<' ';
		}
	}
	return 0;
	
}

