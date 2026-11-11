#include<bits/stdc++.h>
using namespace std;
long long b[2000005],a[2000005],c,t,n,d,k;
void dfs(int op){
	//cout<<op<<' ';
	b[op]++;
	for(int i=op+1;i<=n;i++){
		if(a[i]>a[op]+d){
			return ;
		}
		dfs(i);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int j=1;j<=n-3;j++){
			dfs(j);
			for(int l=j;l<=n;l++){
				if(b[l]==2){
					k++;
				}
				b[l]=0;
			}
		}
		cout<<k<<endl;
		k=0;
	}
	return 0;
} 
