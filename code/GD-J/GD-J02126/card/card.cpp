#include<bits/stdc++.h>
int n,m;
int a[500005],tabel[500005],ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		int ans=0;
		memset(tabel,0,sizeof(tabel));
		for (int j=i-1;j<n;j++){
			bool find=false;int p=0;
			for (int k=i-1;k<j;k++) {
				if(tabel[k]==a[j]) find=true;
				p=k;
			}
			if(!find) tabel[j]=a[j];
			else{
				for (int k=p;k<j;k++) tabel[k]=0;
				tabel[p]=a[j];
			}
		for(int k=0;k<n;k++) if(tabel[k]==i) ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
