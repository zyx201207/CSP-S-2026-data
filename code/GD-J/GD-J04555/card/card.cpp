#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[j]=a[j];
			bool bo=false;
			for(int l=1;l<j;l++){
				if(b[l]==b[j]){
					bo=true;
					break;
				}
			}
			if(bo){
				for(int l=1;l<j;l++){
					b[l]=0;
				}
			}
		}
		for(int j=1;j<=n;j++){
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
