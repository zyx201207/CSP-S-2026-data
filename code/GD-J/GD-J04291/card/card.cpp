#include<bits/stdc++.h>
using namespace std;
int y[500005],u=2,z[300005],y[500005];
bool c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","o",stdout);
	int n,m,a[500005],k=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>y[i];
		k++;
		if(c[a[i]]==1){
			int r=0,o=a[i];
			for(int j=y[a[i]];j<k;j++){
				a[j]=0;
				r++;
			}
			k-=r;
			k++;
			int p=o;
			for(int i=1;i<=k;i++){
				int k=a[i+1];
				a[i]=p;
				a[i+1]=k;
				p=a[i+1];
			}
		}else{
			c[a[i]]=1;
			y[a[i]]=i;
		}
		}
	for(int i=1;i<=m;i++){
		if(c[i]==1) z[i]++;
		cout<<z[i]<<' ';
	}
	return 0;
} 
