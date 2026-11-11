#include<bits/stdc++.h>
using namespace std;
long long a[500005],z[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,x=1,l;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long b[n+1];
		l=1;
		for(int j=i;j<=n;j++){
			b[l]=a[j];
			for(int k=1;k<l;k++){
				if(b[k]==b[l]){
					l=k;
					break;
				}
			}
			l++;
		}
		for(int j=1;j<l;j++){
			z[b[j]]++;
		}
	}
	for(int j=1;j<=m;j++){
		cout<<z[j]<<" ";
	}
	return 0;
}
