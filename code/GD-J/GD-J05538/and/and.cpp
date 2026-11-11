#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ma,ma2,ma3,dpl[200005][2],dpn[200005][2];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma2=max(a[i],ma2);
		if(a[i]!=ma2)ma3=max(a[i],ma3);
	}
	dpl[1][1]=a[1];
	dpl[0][0]=0;
	for(int i=2;i<=n;i++){
		for(int j=min(n,m);j>=0;j--){
			dpn[j][0]=max(dpl[j][0],dpl[j][1]);
			if(j!=0){
				if(j!=1){
					dpn[j][1]=max(dpl[j-1][0]&a[i],dpl[j-1][1]&a[i]);
				}
				else dpn[j][1]=a[i];
			}
			
		}
		for(int j=0;j<=m;j++){
			dpl[j][1]=dpn[j][1];
			dpl[j][0]=dpn[j][0];
		}
	}
	cout<<max(dpn[m][1],dpn[m][0]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
