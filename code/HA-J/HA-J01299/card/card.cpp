#include <bits/stdc++.h>
using namespace std;
int a[200001],b[200001],ans[200001],p[200001];
bool f[200001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	k=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=a[i];
		if(f[a[i]]==0){
			f[a[i]]=1;
			b[a[i]]=i;
		}
		else {
			for(int j=b[a[i]];j<i;j++){
				a[j]=0;
			}
			f[a[i]]=1;
			b[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=0) ans[a[i]]++;
	}
	k--;
	while(k>=1){
		for(int i=1;i<=n;i++){
			f[i]=0;
			b[i]=0;
		}
		for(int i=1;i<=n;i++){
			a[i]=p[i];
		}
		for(int i=n-k+1;i<=n;i++){
			if(f[a[i]]==0){
				f[a[i]]=1;
				b[a[i]]=i;
			}
			else {
				for(int j=b[a[i]];j<i;j++){
					a[j]=0;
				}
				f[a[i]]=1;
				b[a[i]]=i;
			}
		}
		for(int i=n-k+1;i<=n;i++){
			if(a[i]!=0) ans[a[i]]++;
		}
		k--; 
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
