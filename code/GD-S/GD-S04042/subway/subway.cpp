#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500008],k,x,y,remember[500008];
int a[1008][1008],t[1008][1008];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k/2;j++){
			cin>>a[i][j]>>t[i][j];
			remember[a[i][j]]++;
		}
	}
	while(q--){
		cin>>x>>y;
		int cnt=0;
		for(int i=x;i<=y;i++){
			if(i==y){
				cnt+=w[i];
				break;
			}
			else if(i==x){
				cnt+=w[i]+t[i][i];
				continue;
			}
			else if(remember[i]>1){
				while(remember[i]>=1)cnt+=t[i][x],remember[i]--;
			}
			else if(remember[i]==1){
				cnt-=t[i][i];
			}
		}
		cout<<cnt;
	}
	return 0;
}
