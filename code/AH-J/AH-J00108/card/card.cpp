#include <bits/stdc++.h>
using namespace std;
int n,m,pd=1;
int a[500010],ans[300010],zt[500010][2],b[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(zt[a[i]][0]==0){
			zt[a[i]][0]=zt[a[i]][1]=i;
		}
		if(i>1 && a[i]<a[i-1]) pd=0;
		zt[a[i]][1]=max(zt[a[i]][1],i);
	}
	if(pd==1){
		for(int i=1; i<=m; i++) cout<<zt[i][1]<<" ";
		return 0;
	}
	for(int i=1; i<=n; i++){
		memset(b,0,sizeof(b));
		int cnt=0;
		for(int j=i; j<=n; j++){
			int zt=0;
			for(int k=1; k<=cnt; k++){
				if(b[k]==a[j]) zt=k;
				if(zt!=0) b[k]=0;
			}
			if(zt==0) cnt++;
			else cnt=zt;
			b[cnt]=a[j];
		} 
		for(int j=1; j<=cnt; j++) ans[b[j]]++;
	}
	for(int i=1; i<=m; i++) cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
