#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005], cnt[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		long long b[1000005];
		for (int j=i;j<=n;j++){
			b[i]=a[j];
			for (int q=1;q<j;q++){
				if (a[i]==a[q]){
					for (int p=1;p<j;p++){
						b[p]=0;
					}
				}
			}
		}
		for (int j=i;j<=n;j++){
			cnt[b[j]]++;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
}
