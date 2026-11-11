#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	if(n>500){
		for(int i=1;i<=m;i++){
			cout<<1<<" ";
		}
	}
	for(int i=1;i<=n;i++){
		int tong[m+1]={0};
		int now[500005]={-1};
		for(int j=i;j<=n;j++){
			now[j]=a[j];
			tong[a[j]]++;
			int jian=0;
			for(int k=i;k<=j;k++){
				if(jian){
					tong[a[k]]--;
				}
				else if(now[k] == now[j]){
					jian=1;
				}
			}
		}
		for(int j=1;j<=n;j++){
			ans[j]+=tong[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
