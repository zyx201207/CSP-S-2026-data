#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[27891],ans[29178];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int s[50005];
		for(int j=i;j<=n;j++){
			s[a[j]]++;
			if(s[a[j]]==2){
				for(int k=j;k>=i;k--){
					if(a[k]!=a[j]){
						s[a[k]]--;
					}else{
						s[a[j]]--;
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(s[j]==1){
				ans[j]++;
				
			}
			cout<<s[j]<<' ';
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
