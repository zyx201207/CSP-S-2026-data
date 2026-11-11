#include<bits/stdc++.h>
using namespace std;
int a[500005];
int ans[500005];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int pos[m+5]={0},sum[m+5]={0};
		for(int j=i;j<=n;j++){
			sum[a[j]]++;
			if(pos[a[j]]==0){
				pos[a[j]]=j;
			}
			else{
				for(int k=pos[a[j]];k<j;k++){
					if(sum[a[k]]>0){
						sum[a[k]]--;
					}
				}
				pos[a[j]]=j;
			}
			
		}
		for(int j=1;j<=m;j++){
			ans[j]+=sum[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}
