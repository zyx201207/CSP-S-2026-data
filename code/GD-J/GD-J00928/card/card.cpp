#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],b[205]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int le=0;
		int c[505]={0};
		for(int j=i;j<=n;j++){
			bool f=0;
			for(int k=1;k<=le;k++){
				if(c[k]==a[j]){
					for(int l=k;l<=le;i++){
						c[l]=0;
					}
					le=k+1;
					c[le]=a[j];
					f=1;
				}
			}
			if(!f){
				le++;
				c[le]=a[j];
			}
		}
		for(int j=1;j<=le;j++)b[c[j]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
} 
