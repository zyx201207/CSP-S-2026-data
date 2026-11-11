#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+10]={0};
	int ans[m+5]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int str[n+10];
		int r=0;
		for(int j=i;j<=n;j++){
			int t=a[j];
			bool h=0;
			for(int k=r;k>0;k--){
				if(str[k]==t){
					h=1;
					r=k;
					break;
				}
			}
			if(h==0)str[++r]=t;
		}
		for(int j=1;j<=r;j++){
			ans[str[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
