#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a[10000001],n,m,ans[100000001],c[100000001];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=0;
		ans[i]=0;
	}
	for(int i=n;i>=1;i--){
		c[i]++;
		for(int j=i;j<=n;j++){
			for(int y=j+1;y<=n;y++){
				if(a[y]==a[j]){
					c[j]--;
					c[y]++;
				}
			}
		}
	}
	ans[a[1]]+=c[1];
	for(int i=2;i<=n;i++){
		c[i]+=c[i-1];
		ans[a[i]]+=c[i];
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
