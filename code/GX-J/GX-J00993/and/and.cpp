#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	int maxx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>=maxx){
				maxx=a[i];
			}
		}
		cout<<maxx;
		return 0;
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=n;j++){
			int c=a[i]& a[j];
			if(c>=maxx){
				maxx=c;	
			}
		}
	}
	cout<<maxx;
	return 0;
}
