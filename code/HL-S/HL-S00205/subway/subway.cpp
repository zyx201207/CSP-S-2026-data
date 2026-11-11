#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,st,ed;
int w[500005],a[500005],t[500005],f[20000][20000],max1;
int dfs(int x){
	for(int i=1;i<=m;i++){
		if(f[x][i]==1 && i!=ed){
			dfs(i);
			max1++;
		}
		else{
			return max1;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int p=1;p<=j;p++){
				f[a[j]][a[p]]=1;
				f[a[p]][a[j]]=1;
			}
		}
	}
	int sum=0;
	for(int i=1;i<=q;i++){
		sum=0;
		cin>>st>>ed;
		sum+=w[st];
		sum+=w[ed];
		dfs(st);
		sum+=max1*t[1];
		cout<<max1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
