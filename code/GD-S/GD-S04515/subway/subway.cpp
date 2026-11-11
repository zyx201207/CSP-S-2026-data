#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c, n, m, d, q;
	cin>>c>>n>>m>>d>>q;
	long long mp[m+1][m+1];
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=m;j++){
			mp[i][j]=2e9;
		}
	}
	for(long long i=1;i<=m;i++){
		cin>>mp[i][i];
	}
	for(long long i=1;i<=n;i++){
		long long k;
		cin>>k;
		long long s[k+1]={};
		long long t[k+1]={};
		for(long long j=1;j<=k;j++){
			cin>>s[j]>>t[j];
		}
		for(long long j=1;j<k;j++){
			for(long long l=j+1;l<=k;l++){
				mp[s[j]][s[l]]=min(t[j]+t[l],mp[s[j]][s[l]]);
				mp[s[l]][s[j]]=mp[s[j]][s[l]];
			}
		}
	}
	for(long long p=1;p<=q;p++){
		long long s,z;
		cin>>s>>z;
		while(mp[s][z]==2e9){
			for(long long i=1;i<=m;i++){
				for(long long j=1;j<=m;j++){
					for(long long k=1;k<=m;k++){
						if(k==i)
						continue;
						mp[i][j]=min(mp[i][j],mp[i][k]+mp[j][k]);
						mp[j][i]=mp[i][j];
					}
				}
			}
		}
	cout<<(mp[s][z]+mp[s][s]+mp[z][z])<<endl;
	}
	return 0;
}
