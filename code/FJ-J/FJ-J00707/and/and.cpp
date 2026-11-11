#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;

	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		int maxx=a[1];
		for(int i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
	} 
	else if(m==2){
		int maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					int an=a[i]&a[j];
					maxx=max(an,maxx);
				}
			}
		}
		cout<<maxx;
	}
	else{
		sort(a+1,a+n+1);
		int ans=a[n];
		for(int i=n-1;i>n-m;i--){
			ans&=a[i];
		}
		cout<<ans;
	}
	return 0;
} 
