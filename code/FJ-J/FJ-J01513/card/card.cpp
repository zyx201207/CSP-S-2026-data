#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010],k[100010],ans[100010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i]){
			f=false;
		}
	}
	if(f){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				cout<<i<<" ";
			}
		}
	}else{
		for(int i=1;i<=n;i++){
		int t=0;
		for(int j=i;j<=n;j++){
			for(int l=t;l>=1;l--){
				if(k[l]==a[j]){
					t=l-1;
					break;
				}
			}
			k[++t]=a[j];
		}
		for(int j=1;j<=t;j++){
			ans[k[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}	
	}

	return 0;
}
