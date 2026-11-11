#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[300005];
bool is[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)is[j]=1;
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				if(a[k]==a[j]&&is[k]){
					for(int o=k;o<j;o++)is[o]=0;
					break;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(is[j])ans[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
