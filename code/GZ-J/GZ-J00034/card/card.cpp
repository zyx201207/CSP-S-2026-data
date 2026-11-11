//GZ-J00034，邵葛锦华，贵阳市观山湖区外国语实验中学 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],f[300005],tong[300005],z[500005],bh[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	int zlen=1;
	for(int i=1;i<=n;i++){
		zlen=1;
		memset(z,0,sizeof(z));
		memset(tong,0,sizeof(tong));
		for(int j=i;j<=n;j++){
			if(tong[a[j]]!=0){
				int p=bh[a[j]];
				for(int k=bh[a[j]];k<zlen;k++){
					tong[z[k]]=0;
					bh[a[j]]=0;
				} 
				zlen=p;
			}
			z[zlen++]=a[j];
			tong[a[j]]=j;
			bh[a[j]]=zlen-1;
		}
		for(int k=1;k<zlen;k++){
			f[z[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
