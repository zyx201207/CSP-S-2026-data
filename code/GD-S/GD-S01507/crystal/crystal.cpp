#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[600000];
int x[600000][600000]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int max=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1); 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			x[i][j]=x[i][j-1]+a[j]-a[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(x[i][1]>m)i+=1;
		for(int j=i;j<=n;j++){
			if(x[i][1]>m)break;
			if(x[i][j]<=m&&x[i][j+1]>m&&i>max){
				max=i;
				break;
			}
		}
	}
	cout<<max;
	return 0;
}
	//int z=0;
	//sort(a+1,a+n+1);
	//for(int i=1;i<=n;i++){
	//	for(int j=1;j<=i;j++){
	//		int x=0;
	//		int y=0;
	//		if((a[i]-a[j])*(i-j)/2>m){
	//			y=0;
	//		}
	//		else if(a[i]-a[j]<=m){
	//			for(int l=j;l<=i;l++){
	//				x+=a[i]-a[l];
	//				y++;
	//			}
	//		}
	//		if(x<=m&&y>=z)z=y;
	//	}
	//}
	//cout<<z;
	//return 0;
 
