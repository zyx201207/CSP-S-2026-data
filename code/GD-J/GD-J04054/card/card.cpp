#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long a[5*N+5],b[3*N+5],vis[3*N+5],nown[5*N+5];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			nown[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<nown[m]<<' ';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
