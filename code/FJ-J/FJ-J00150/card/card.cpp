#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a[100005],ans[100005],b[100005],c[100005];
	int n,m,r=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=r;k++){
				if(a[k]==b[j]){
					r=k-1;
					break;
				}
			}
			r++;
			a[r]=b[j];
		}
		for(int j=1;j<=r;j++){
			ans[a[j]]++;
			a[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
