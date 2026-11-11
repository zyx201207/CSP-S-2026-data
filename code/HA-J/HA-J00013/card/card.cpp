#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
bool A;
int b[500010];
int bj[300010];
long long ans[300010];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	A=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])A=0;
	}
//	if(A){
//		
//		return 0;
//	}
	int ti;
	for(int i=1;i<=n;i++){
		ti=0;
		memset(bj,0,sizeof(bj));
//		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(bj[a[j]]!=0){
				ti=bj[a[j]];
			}
			else{
				++ti;
				bj[a[j]]=ti;
			}
			b[ti]=a[j];
		
		}
			for(int k=1;k<=ti;k++){
				cout<<b[k]<<"*";
			}cout<<'\n';
		for(int j=1;j<=ti;j++){
			ans[b[j]]++;
		}cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
