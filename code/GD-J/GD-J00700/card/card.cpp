#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j=1;j<=m;j++){
		int ans=0;
		if(j==a[n]){
			cout<<n<<' ';
			continue;
		}
		for(int i=1;i<=n;i++){
			int b[m+1],p=1;
			for(int k=1;k<=m;k++) b[k]=0;
			if(j==a[i]){
				ans++;
				continue;
			}
			for(int k=i;k<=n;k++){
				b[a[k]]++;
				if(b[a[k]]>=2){
					p=0;
					break;
				}
			}
			if(p&&b[j]) ans++;
		}
		cout<<ans<<' ';
	}
	return 0;
}
