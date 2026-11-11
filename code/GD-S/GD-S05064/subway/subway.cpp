#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q ,i,j;
int w[500000],k[500],a[500][500000],t[500][500000],x,y;
long long f(){
	int ans,Min,I,J,l,r;
	for( l=0;l<n;l++){
		int ok=0;
		ans=0;
		for( I=0;I<k[l];I++){
			if(a[l][I]==x){
				ok=1;
				break; 
			}
		}
		if(ok){
			for( r=0;r<n;r++){
				ok=0,ans=w[x]+t[l][I];
				for( I=0;I<k[r];I++){
					if(a[r][I]==y){
						ok=1;
						break;
					}
				}
				if(ok){
					for( I=0;I<k[r];I++){
						ans=w[x]+t[l][I];
						for( J=0;J<k[l];J++){
							if(a[r][I]==a[l][J]){
								ans+=w[x]+t[l][I]+t[l][J]+t[r][I]+t[r][I]+w[y];
							}
						}
					}
				}
			}
		}
	}
	return Min;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(i=0;i<m;i++) cin>>w[i];
	for(i=0;i<n;i++){
		cin>>k[i];
		for(j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(i=0;i<q;i++){
		cin>>x>>y;
	}
	return 0;
}
