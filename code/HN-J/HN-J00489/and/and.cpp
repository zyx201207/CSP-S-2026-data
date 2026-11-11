#include<bits/stdc++.h>
using namespace std;
int n,m,a[10056],maxx=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>=maxx) maxx=a[i];
		}
		cout<<maxx;
		return 0;
	}
	for(int i=1;i<=m;i++){
		maxx=0;
		for(int j=1;j<=n;j++){
			if(a[j]>=maxx){
				maxx=a[j]; 
			}	
		}
		for(int j=1;j<=n;j++){
			if(a[j]==maxx) a[j]=0;
		}
	}
	cout<<maxx;
	return 0;
}
