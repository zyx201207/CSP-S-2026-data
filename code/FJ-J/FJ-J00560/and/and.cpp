#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans;
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxs=0,d;
	for(int i=1;i<=m;i++){
		maxs=0;d=0;
		for(int j=1;j<=n;j++){
			if(maxs<a[j]){
				maxs=a[j];
				d=j;
			}
		}
		if(i==1){
			ans=maxs;
		}else{
			ans=ans&maxs;
		}
		a[d]=-1;
	}
	cout<<ans;
	return 0;
}
