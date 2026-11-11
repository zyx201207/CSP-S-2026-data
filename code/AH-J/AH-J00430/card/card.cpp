#include<bits/stdc++.h>
using namespace std;
long long b[550000]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a[550000];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	b[a[n]]++;
	for(int i=n-1;i>=1;i--){
		for(int j=i;j<=n;j++){
			int f=2;
			for(int k=j+1;k<=n;k++){
				if(a[k]==a[j]){
					j=k-1;
					f--;
				}
			}
			if(f==2){
				b[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
