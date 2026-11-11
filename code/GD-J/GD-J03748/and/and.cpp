#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int a[200005],b[35][200005],c[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		int x=a[i];
//		int	d=30;
//		while(d>=0){	
//			if(x-pow(2,d)>=0){
//				c[d]++;
//				b[d][c[d]]==a[i];
//				x-=pow(2,d);
//			}
//			d--;
//		}
//	}
//	for(int i=30;i>=0;i--){
//		if(c[i]>=m){
//			ans=b[i][c[i]];
//			for(int j=c[i];j>=c[i]-m+1;j--){
//				cout<<b[i][c[i]]<<" ";
//				ans&=b[i][c[i]];
//			}
//			cout<<ans;
//			return 0;
//		}
	int ans=a[n];
	for(int i=n;i>=n-m+1;i--){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
