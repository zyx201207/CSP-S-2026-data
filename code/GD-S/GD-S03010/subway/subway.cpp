#include<bits/stdc++.h>
using namespace std;
long long c;
long long n,m,d,q;
long long l,r;
long long w[500050],k[550],ans=0;
long long a[505][5005],t[505][5005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		ans=0;
		cin>>l>>r;
		ans+=w[l];
		ans+=w[r];
		for(int j=1;j<=k[1];j++){
			ans+=t[1][j];
			if(j==r-l+1){
				break;
			}
		}
		long long sum;
		for(int i=2;i<=n;i++){
			sum=w[l]+w[r];
			for(int j=1;j<=k[i];j++){
				sum+=t[i][j];
				if(j==r-l+1){
					break;
				}
			}
			ans=min(ans,sum);
		}
		cout<<ans<<endl;
	}
	return 0;
}
