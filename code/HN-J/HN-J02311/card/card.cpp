#include <bits/stdc++.h> 
using namespace std;

int a[500010]={},n,m,p[500010]={},cnt[300010]={};

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		p[i-1]=0;
		for(int j=i;j<=n;j++){
			p[j]=a[j];
			for(int k=i;k<=j-1;k++){
				if(p[k]==p[j]){
					for(int l=k;l<=j-1;l++){
						p[l]=0;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			cnt[p[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout << cnt[i] << " ";
	}
	return 0;
}
