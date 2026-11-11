#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int NN=1e5+10;
int a[N],r[NN],ans[NN],b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	bool f=1;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		r[a[i]]=i;
		if(a[i]<a[i-1]){
			f=0;
		}
	}
	if(f){
		for(int i=n;i>=1;i--){
			if(i==n||a[i]!=a[i+1])ans[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout << ans[i] <<' '; 
		}
	}else if(m==2){
		for(int i=1;i<=n;i++){
			if(a[i]==a[n]){
				ans[a[i]]++;
			}else if(a[i]!=a[n]){
				ans[a[i]]++;
				ans[a[n]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout << ans[i] << ' ';
		}
	}else{
		for(int i=1;i<=n;i++){
			memset(b,1,sizeof b);
			for(int j=i;j<=n;j++){
				if(b[j]==0)continue;
				for(int k=j;k<r[a[j]];k++){
					b[k]=0;
				}
			}
			for(int j=i;j<=n;j++){
				if(b[j])ans[a[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout << ans[i] << ' ';
		}
	}
	return 0;
} 

