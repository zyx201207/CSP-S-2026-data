#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}//cout<<"666";
	if(m==2){
		int maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
		return 0;
	}
	
	
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
			cout<<ans;
		}
	}
	return 0;
}
