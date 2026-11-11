#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[500010];
int s[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			s[j]=a[j];
			for(int k=i;k<j;k++){
				if(s[k]==a[j]){
					s[k]=0;
				}
			}
		}
		for(int j=1;j<=m;j++){
			for(int k=i;k<=n;k++){
				if(j==s[k]){
					ans[j]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}         						
