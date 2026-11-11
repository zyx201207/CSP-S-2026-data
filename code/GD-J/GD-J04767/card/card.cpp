#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	int b[n+5];
	int Sum[m+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[i]=a[i];
		}
		for(int j=1;j<=n-i+1;j++){
			for(int k=1;k<=n-i+1;k++){
				if(b[j]==b[k]&&j!=k){
					for(int l=j;l<k;l++){
						b[l]=0;
					}
					for(int l=1;l<=n-i+1;l++){
						if(b[l]!=0){
							Sum[b[l]]++;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<Sum[i]<<' ';
	}
	return 0;
} 
