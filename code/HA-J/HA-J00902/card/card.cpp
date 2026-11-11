#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],s[10005],aa[10005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		aa[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int ii=1;ii<=n;ii++){
			aa[ii]=a[ii];
		}
		for(int j=i+1;j<=n;j++){
			if(aa[i]==aa[j]){
				for(int k=i;k<j;k++){
					aa[k]=0;
				}
			}
		}
		for(int j=1;j<=n;j++){
			s[aa[j]]++;
		}
	}
	for(int j=1;j<=m;j++){
		cout<<s[j]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
