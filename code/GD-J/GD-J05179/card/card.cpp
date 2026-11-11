#include<bits/stdc++.h>
using namespace std;
int const N=500010;
int n,m;
int a[N],ans[N],f[N],is[N];
void de(int q,int k){
	for(int i=is[k]+1;i<q;i++){
		f[a[i]]=0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		memset(is,0,sizeof(is));
		for(int j=i;j<=n;j++){
			if(f[a[j]]){
				de(j,a[j]);
				is[a[j]]=j;	
			}else{
				f[a[j]]=1;
				is[a[j]]=j;
			}
		}
		for(int i=1;i<=m;i++){
			if(f[i]){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

