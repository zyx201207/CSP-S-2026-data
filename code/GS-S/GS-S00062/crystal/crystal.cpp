#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int  a[100000];
int main(){
	freopen("crytal.in","r",stdin);
	freopen("crytal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			for (int k=1;k<=n;k++){
					if (a[j]+a[k]==a[j]){
						a[j]+=1;
						ans+=1;
					}
			}
		}		
	}
	cout<<ans;
	return 0;
}
