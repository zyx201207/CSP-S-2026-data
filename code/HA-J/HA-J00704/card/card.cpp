#include<bits/stdc++.h>
using namespace std;
int a[500005],k[300005],ans[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool A=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[i-1])A=0;
	} 
	if(A){
		for(int i=1;i<=n;i++){
			k[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<k[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			k[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(k[a[j]]==0){
				k[a[j]]=j;
			}else{
				for(int p=k[a[j]];p<j;p++){
					k[a[p]]=0;
				}
				k[a[j]]=j;
			}
		}
		for(int i=1;i<=n;i++){
			if(k[i]){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}


