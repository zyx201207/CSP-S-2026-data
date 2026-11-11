#include<bits/stdc++.h>
using namespace std;
int a[5000005];
int ans[250000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(n--){
		for(int i=2;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]==a[j]){
					ans[i]=a[j];
					
				}
			}
		}
	}
	cout<<0;
	return 0;
}
