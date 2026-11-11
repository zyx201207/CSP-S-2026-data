#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[500001];
	int ans[500001];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int s=1;s<=n;s++){
		int w[500001]={};
		for(int i=s;i<=n;i++){
			for(int j=s+1;j<=n;j++){
				w[j]+1;
				if(a[j]==a[i]){
					w[i]+1;
					break;
				}
			}
		}
		for(int i=s;i<=n;i++){
			if(w[i]==1){
				ans[w[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
