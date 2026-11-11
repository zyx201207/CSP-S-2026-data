#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[10005],a[10005][10005],t[10005][10005],x[10005],y[10005];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	int k,abk=0;
	for(int i=0;i<n;i++){
		cin>>k;
		abk=max(abk,k);
		for(int j=0;j<k;j++){
			cin>>a[k][j]>>t[k][j];
		}
	}
	for(int i=0;i<q;i++){
		cin>>x[q]>>y[q];
	}
	int add=0;
	int dp[10005];
	for(int i=0;i<abk;i++){
		for(int j=0;j<n;j++){
			for(int l=0;l<n;l++){
				if(a[i][j]==a[i+1][l]){
					add+=t[i+q][l];
					dp[i]=a[i+1][j];
				}
			}
		}
	}
	int add2[10005];
	
	for(int i;i<q;i++){
		add2[i]+=w[x[i]]+w[y[i]];s
	}
	for(int i=0;i<q;i++){
		for(int j=0;j<n;j++){
			
			add2[i]+=t[i][j];
			add2[i]=add2[i]-t[dp[i]][j];
			add2[i]=add2[i]-t[dp[i]][j];
			add2[i]=add2[i]-add;
		}
		cout<<add2;
	}
	return 0;
}
