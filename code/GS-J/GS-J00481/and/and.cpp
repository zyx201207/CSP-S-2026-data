#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans1=0,ans2=0;
	cin>>n>>m; 
	for(int i=0;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m*n;j++){
			for(int l=0;l<=m;l++){
				ans1+=a[i] and a[j+1];
			} 
		}
		if(ans2<ans1)ans2=ans1; 
	}
	cout<<ans2;
	return 0;
}
