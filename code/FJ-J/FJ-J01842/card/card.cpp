#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],num,b[1000000],ans;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans=0;
		num=0;
		for(int j=i+1;j<=n;j++){
			for(int k=i;k<j;k++){
				if(k<ans || k>=num){
					if(a[k]==a[j]){
						num=j;
						ans=k;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(j<ans || j>=num){
				b[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
