#include<bits/stdc++.h>
using namespace std;
int main (){
	int n,m;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	long long  a[m+1],d[m+1],deshu=0;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>d[i];
		long long  z[m+1][a[i]];
		for(int j=1;j<=a[i];j++){
			cin>>z[i][j];
		}
		long long  cha[a[i]],f=0,he=0;
		for(int k=2;i<=a[i];k++){
			if(z[i][k]-z[i][k-1]<=d[i]){
				f++;
				cha[f]=z[i][k]-z[i][k-1];
				he+=cha[f];
			}else{
				break;
			}
		}
		for(int j=f;j>=1;j--){
			if(he%d[i]==0){
				he-=cha[j];
			}else if(he%d[i]!=0&&he/d[i]==1){
				deshu++;
			}
		}
		for(int j=1;j<=f-1;j++){
			if(he%d[i]==0){
				he-=cha[i];
			}else if(he%d[i]!=0&&he/d[i]==1){
				deshu++;
			}
		}
	cout<<deshu<<endl;}
	return 0;
}

