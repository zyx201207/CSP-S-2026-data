#include <bits/stdc++.h>
using namespace std;

const int MAXN(2E6+5);
int a[MAXN];
int ans[MAXN];
int f[MAXN];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n<<endl;
		return 0;
	}
	if(n==m){
		for(int i=1;i<=m;i++){
			cout<<n<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[a[j]]==0){
				f[a[j]]=j;
			}else{
				for(int k=1;k<=m;k++){
					if(f[k]>f[a[j]]){
						f[k]=0;
					}
				}
				f[a[j]]=j;
			}
						
		}
		for(int j=1;j<=m;j++){
			if(f[j]){
				ans[j]++;
			}
		}
		memset(f,0,sizeof f);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}