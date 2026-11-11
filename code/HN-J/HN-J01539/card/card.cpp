#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[100010],b[100010],ans[100010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=i;k<j;k++){
				if(a[k]==a[j]){
					for(int q=k;q<j;q++){
						a[q]=0;
					}
					break;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(a[j]){
				ans[b[j]]++;
			}
		}
		for(int j=1;j<=n;j++){
			a[j]=b[j];
		}
	}
	for(int i=1;i<=100010;i++){
		if(m==0) break;
		if(ans[i]){
			cout<<ans[i]<<" ";
			m--;
		}
	}
	return 0;
} 
