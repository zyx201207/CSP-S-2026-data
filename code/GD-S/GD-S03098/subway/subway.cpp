#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500001],k[500001],a[500001][500001],t[500001][500001],x[100001],y[100001],maybe[100000];
int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
	// ‰»Î
	long long z=0;
	for(int i=1;i<=q;i++){
		int minn=0x3f3f3f3f;
		for(int j=1;j<=n;j++){
			for(int o=1;o<=k[j];o++){
				if(x[i]==a[j][o]){
					maybe[z]+=t[j][o];
					for(int e=1;e<=k[j];e++){
						maybe[z]+=2*t[j][e];
						for(int l=1;l<=n;l++){
							for(int v=1;v<=k[l];v++){
								if(a[j][o]==a[l][v]){
									maybe[z]+=2*t[l][v];
								}
								else continue;
							}
						}
					}
				}
				else return;
			}
			z++;
		}
		cout<<maybe[z]
	}
}
