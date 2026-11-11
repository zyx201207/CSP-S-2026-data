#include<bits/stdc++.h>
using namespace std;
int c[100005],a[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		int b[m+1];
		b[1]=c[i];
		if(i!=n){
			for(int j=i+1;j<=n;j++){
				int d=0;
				for(int l=1;l<=m;l++){
					if(b[l]==c[j]){
						for(int k=l+1;k<=m;k++){
							b[k]=0;
						}
						d=1;
						break;
					}
				}
				if(d==0){
					for(int l=1;l<=m;l++){
						if(b[l]==0){
							b[l]=c[j];
							break;
						}
					}
				}
			}
		}
		for(int j=1;j<=m;j++){
			int x=b[j];
			a[x]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
