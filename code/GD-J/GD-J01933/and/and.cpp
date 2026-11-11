#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,i,a[N],j,k,l;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	if(m==1){
		int ma=0;
		for(i=0;i<n;i++) ma=max(ma,a[i]);
		printf("%d",ma);
	}
	if(m==n){
		int ans=a[0];
		for(i=1;i<n;i++) ans=ans&a[i];
		printf("%d",ans);
	}
	if(m==2){
		int ma=0;
		for(i=0;i<n;i++) for(j=i+1;j<n;j++) ma=max(ma,a[i]&a[j]);
		printf("%d",ma);
	}
	if(m==3){
		int ma=0;
		for(i=0;i<n;i++) for(j=i+1;j<n;j++) for(k=j+1;k<n;k++) ma=max(ma,a[i]&a[j]&a[k]);
		printf("%d",ma);
	}
	if(m==4){
		int ma=0;
		for(i=0;i<n;i++) for(j=i+1;j<n;j++) for(k=j+1;k<n;k++) for(l=k+1;l<n;l++) ma=max(ma,a[i]&a[j]&a[k]&a[l]);
		printf("%d",ma);
	}
	if(m==n-1){
		int ma=0;
		for(i=0;i<n;i++){
			int ans=i==0?a[1]:a[0];
			for(j=0;j<n;j++){
				if(i==j) continue;
				ans=ans&a[j];
			}
			ma=max(ma,ans);
		}
		printf("%d",ma);
	}
	return 0;
}
