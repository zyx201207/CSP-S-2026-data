#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],z[300005],Y[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int l=i;
		for(int j=i;i<=n;j++){
			bool k=0;
			for(int l1=l;l1>1;l1--){
				if(a[j]==Y[l]){
					k=1;
					l=l1;
					break;
				}
			}
			if(k){
				for(int l1=l;l1<=j;l1++){
					Y[l]=0;
				}
			}
			Y[l]=a[j];
			l++;
		}
		for(int j=1;j<=l;j++){
			z[Y[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<z[i]<<' ';
	}
	return 0;
}
