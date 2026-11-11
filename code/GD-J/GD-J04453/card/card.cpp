#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int q[n+1],idx=0;
		for(int j=i;j<=n;j++){
			q[++idx]=a[j];
			for(int k=1;k<idx;k++){
				if(q[k]!=-1){
					if(q[k]==a[j]){
						for(int p=k;p<idx;p++){
							a[p]=-1;
						}
					}
				}
			}
		}
		bool v[m+1]={0};
		for(int j=1;j<=idx;j++){
			if(q[j]!=-1){
				v[q[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(v[j]){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
