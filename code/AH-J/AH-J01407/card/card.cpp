#include<bits/stdc++.h>
using namespace std;
long long n,m,x,a[500000+10],sum1,sum2,b[500000+10],c[500000+10],bh,d[500000+10];
bool bol;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1) cout<<1;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(!c[a[j]]){
					b[j]=a[j];
					bol=0;
					for(int k=j-1;k>=1;k--){
						if(b[k]==b[j]){
							bh=k;
							bol=1;
							break;
						}
					}
					if(bol){
						for(int k=bh;k<j;k++){
							c[b[k]]=1;
							b[k]=0;
						}
					}
				}
				else b[j]=0;
			}
			for(int j=i;j<=n;j++){
				d[b[j]]++;
			}
			for(int j=1;j<=m;j++) c[j]=0;
		}
		for(int i=1;i<=m;i++) cout<<d[i]<<" ";
	}
	return 0;
}
