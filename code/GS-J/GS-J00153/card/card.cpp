#include <bits/stdc++.h>
using namespace std;
long long a[10005];
long long b[10005];
long long num=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long ans[m];
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=num;i<=n;i++){
		a[i]=b[i];
		if(i>num){
			for(int j=1;j<=i;j++){
				if(a[j]==a[i]){
					for(int k=j;k<=i;k++){
						a[k]=0;
					}
				}
			}
		}
		for(int l=num;l<=n;l++){
			if(a[l]!=0) ans[l]++;
		}
		num++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[a[i]]<<" ";
	}
}
