#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int q[500005];
int sum[500005];
int e=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		e=i;
		for (int j=i;j<=n;j++){
			bool flag=0;
			for (int k=i;k<=e;k++){
				if (q[k]==a[j]){
					for (int p=k+1;p<=e;p++){
						q[p]=0;
					}
					flag=1;
					e=k;
					break;
				}
			}
			if (!flag){
				e++;
				q[e]=a[j];
			}
		}
		for (int j=i;j<=e;j++){
			sum[q[j]]++;
			q[j]=0;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
