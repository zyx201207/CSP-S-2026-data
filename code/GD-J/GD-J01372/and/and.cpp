#include<bits/stdc++.h>
using namespace std;
int n,m,nm[100001],max1=-9999999,o[100001],max2=-9999999;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		nm[i]=k;
	}
	for(int i=1;i<=n-1;i++){
		int o1=nm[i];
		for(int j=1;j<=m-1;j++){
			for(int z=i+1;z<=n;z++){
				if(max1<(o1&nm[z])&&o[z]==0){
					max1=nm[i]&nm[z];
					o[z]=1;
				}
			}
			o1=max1;
			max1=-99999999;
		}
		for(int j=1;j<=n;j++){
			o[j]=0;
		}
		max2=max(max2,o1);
	}
	cout<<max2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
