#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	#define int long long
	int c,n,m,d,q,w[1000000],k[100000],a[100000][100000],t[100000][100000],l=1,s,e;
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
	if(l<=q){
		int ans=0;
		cin>>s>>e;
		int mn,x=0,z,y,o=0;
		for(int i=1;i<=n;i++){
			int j=1,mi=1e9;
			if(a[i][j]!=s&&j<k[i]) j++;
			else if(a[i][j]==s){
				int f=0;
				if(mi>t[i][j]) {
					mi=t[i][j];
					z=i;
					y=j;
				}
				for(int h=y;h<=k[z];h++){
					if(e-a[z][h]>0){
						mn=e-a[z][h];
					}
					if(e-a[z][h]==0) {
						cout<<ans+w[x]+w[e]+o*t[1][1];
						continue;
					}
					s=e-mn;
					o++;
				}
			}		
		}
		l++;
		ans+=o*t[1][1];
		cout<<ans+w[x]+w[e];
	}
	return 0;
}
