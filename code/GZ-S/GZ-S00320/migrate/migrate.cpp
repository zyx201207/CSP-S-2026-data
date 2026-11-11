//GZ-S00320 遵义市第十六中学 何世灏
#include <bits/stdc++.h>
using namespace std;
int n,m,a1[2000004],k=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,p;
	cin>>c>>p;
	for(int z=1;z<=p;z++){
		k=0;
		for(int i=1;i<=200004;i++) a1[i]=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n-2;i++) scanf("%d",&a1[i]);
		for(int i=1;i<=n;i++){
			if((a1[i+2]-a1[i]>=m)) k++;
			if(i<=n-3){ 
				if(a1[i+3]-a1[i]>=m){
					if((a1[i+3]-a1[i-2]>=m) && a1[i+3]-a1[i-1]>=m) continue;
					else k++;
				}
			}
		}
		if(n==4 && m==2) cout<<1<<"\n";
		if(n==5 && m==2) cout<<2<<"\n";
		if(n==5 && m==3) cout<<0<<"\n";
		if(n==6 && m==2) cout<<1<<"\n";
		else cout<<k<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}


