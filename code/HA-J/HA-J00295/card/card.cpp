#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	char a[n+1];
	int ans[m+1];
	fill(ans,ans+m,0);
	for(int i=0;i<n;i++)
	cin>>a[i];
	int k[n+1];
	fill(k,k+n,0);
	for(int i=0;i<n;i++){
		int j;
		for(j=0;j<i;j++){
			if(k[j]==a[i]){
				fill(k+j,k+n,0);
			}
		}
		k[j]=a[i];
		for(int s=0;s<=j;s++)
		ans[k[s]-1]++;
	}
	for(int i=0;i<m;i++)
	cout<<ans[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
