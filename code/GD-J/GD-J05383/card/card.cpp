#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m;
long long a[500005];
long long b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		int t=i;
		for (int j=i;j<=n;j++){
			int k=j+1;
			while (a[k]!=a[j] && k<=n){
				k++;
			}//cout<<k<<"s ";
			if (k<=n){
				j=k;t=k;
			}//cout<<j<<"j ";
		}//cout<<endl<<t<<endl;
		for (int j=t;j<=n;j++){
			b[a[j]]++;
		}
	}for (int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
}
