#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
int a[200090][30],x=1;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,y;
	cin>>n>>y;
	for(int i=1;i<=n;i++){
		x=1;
		cin>>a[i][0];
		for(int j=1;j<=30;j++){
			if((a[i][0]&x)>=x){
				a[i][j]=1;
			}
			x*=2;
		}
	}
	int x1=0,z=0;
	for(int i=1;i+y<=n;i++){
		int l=0;
		for(int j=30;j>=1;j--){
			for(int k=i;k<=i+y;k++){
				if(l!=0&&a[k][j]==1){
					l++;
				}
				else if(l==0&&a[k][j]==1){
					l++;
				}
				else if(l!=0&&a[k][j]!=1){
					l=0;
				}
				if(l==y){
					x1=i;
					break;
				}
			}
			if(x1!=0){
				break;
			}
		}
		if(x1!=0){
			break;
		}
	}
	z=a[x1][0];
	for(int i=x1+1;i<=x1+y;i++){
		z=z&a[i][0];
	}
	cout<<z;
	return 0;
} 
