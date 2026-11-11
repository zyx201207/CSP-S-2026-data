#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],js[N],i,j,k,l,v[N],no;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	for(i=0;i<n;i++){
		no=0;
		for(j=i;j<n;j++){
			for(k=0;k<no;k++){
				if(a[j]==v[k]){
					for(l=k;l<n;l++) v[k]=0;
					no=k;
					break;
				}
			}
			v[no++]=a[j];
		}
		for(j=0;j<no;j++){
			js[v[j]]++;
			v[j]=0;
		}
	}
	sort(a,a+n);
	for(i=0;i<n;i++){
		bool f=1;
		for(j=0;j<i;j++){
			if(a[j]==a[i]){
				f=0;
				break;
			}
		}
		if(f) printf("%d ",js[a[i]]);
	}
	return 0;
}
