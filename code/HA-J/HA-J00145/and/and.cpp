#include<bits/stdc++.h>
using namespace std;
int n,m;
int r[200005][30];
int arr[200005];
int ans[30];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1);
	for(int i=1;i<=n;i++){
		int a;
		a=arr[i];
		int cnt=1;
		for(int j=1;j<=30;j++){
			r[i][j]=r[i-1][j];
		}
		while(a!=0){
			r[i][cnt]+=(a%2);
			a/=2;
			cnt++;
		}
	}
	for(int i=m;i<=n;i++){
		for(int j=30;j>=1;j--){
			int a=r[i][j]-r[i-m][j];
			a=max(0,a-m+1);
			if(a>ans[j]){
				for(int k=j;k>=1;k--){
					ans[k]=max(0,r[i][k]-r[i-m][k]-m+1);
				}
				break;
			}
			else if(a<ans[j]){
				break;
			}
		}
	}
	int a=0;
	for(int i=30;i>=1;i--){
		a*=2;
		a+=ans[i];
	}
	cout<<a;
	return 0;
}
