#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005],ans[500005];
long long findd(long long q,int p){
	for(int i=1;i<=p;i++){
		if(a[i]==q){
			return i;
		}
	}
	return -1;
}
void back_first(){
	for(int i=1;i<=n;i++) c[i]=a[i];
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		back_first();
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				if(c[k]==c[j]){
					for(int l=k;l<j;l++){
						c[l]=-1;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(c[j]!=-1) ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
