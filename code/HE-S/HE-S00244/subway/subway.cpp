#include<bits/stdc++.h>
using namespace std;
struct xl{
	int k;
	int z[10000];
	int t[10000];
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m+1];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	xl a[n];
	for(int i=0;i<n;i++){
		cin>>a[i].k;
		for(int j=0;j<a[i].k;j++){
			cin>>a[i].z[j]>>a[i].t[j];
		}
	}
	int p[q][2];
	for(int i=0;i<q;i++){
		cin>>p[i][0]>>p[i][1];
	}
	int ti=0;
	if(d==2){
		for(int u=0;u<q;u++){
			for(int i=0;i<n;i++){
				int k1=a[i].k;
				for(int j=0;j<q;j++){
					int k2=a[j].k;
					for(int l=0;l<k1;l++){
						if(a[i].z[l]!=p[u][0]){
							continue;
						}
						for(int r=0;r<k2;r++){
							if(a[j].z[r]==p[u][1]){
								for(int i1=l;i1<k1;i1++){
									for(int i2=r;i2>0;i2--){
										if(a[i].z[i1]==a[j].z[i2]){
											t1+=a[i].t[i1];
											t1+=a[j].t[i2];
											t1+=w[a[i].z[i1]];
											cout<<t;
											return 0;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}
