#include<bits/stdc++.h>
using namespace std;
int n,m,a[500050],b[300050],sum[300050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			sum[a[j]]++;
			j=b[a[j]]+1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
