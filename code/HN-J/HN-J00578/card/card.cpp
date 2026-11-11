#include<bits/stdc++.h>
using namespace std;
int n,m,a[600000]={0},cnt[600000]={0},z[600000]={0},zcnt=0;
int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	if(m==1){
		cout<<n*(n+1)/2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;i<=n;i++){
			z[zcnt+1]=a[j];
			zcnt++;
		}
		for(int j=1;j<=zcnt;j++){
			cnt[z[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i];
	}
	return 0;
}
