#include<bits/stdc++.h>
using namespace std;
int w[500005],a[505][2],r[505][2];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	char c;
	int n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++) {
		int x;
		cin>>x;
		for(int j=1;j<=i;j++) cin>>a[j][1]>>a[j][2];
	}
	for(int i=1;i<=q;i++){
		int cnt=0;
		cin>>r[i][1]>>r[i][2];
		cnt+=w[r[i][1]]+w[r[i][2]];
		for(int j=r[i][1];j<=r[i][2];j++){
			 for(int k=1;k<=n;k++){
				 if(a[k][1]==j) cnt+=a[k][2];
			 }
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}

