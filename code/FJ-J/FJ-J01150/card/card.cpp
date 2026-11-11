#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int n,m;
int ans[N];
int x[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int k=1;k<=n;k++){
		int a[500005]={};
		for(int j=k;j<=n;j++){
			int f=j;
			for(int i=k;i<=j;i++){
				if(a[i]==x[j]){
					f=i;
					for(int z=i;z<=j;z++){
						a[z]=0;
					}
					break;
				}
			}
			a[f]=x[j];
		}
		for(int i=1;i<=n;i++){
			ans[a[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
