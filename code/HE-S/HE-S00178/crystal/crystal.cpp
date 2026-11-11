#include<bits/stdc++.h>
//#define ll long long
using namespace std;
//const long long MAXN=50005;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a[505],b[505],c[505][505],n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<n;i++)b[i]=a[i+1]-a[i];
	for(int i=1;i<n;i++)for(int j=i;j<n;j++)c[i][j]=a[j+1]-a[i];
	int d=-1;
//		for(int i=1;i<n;i++)for(int j=i;j<n;j++)cout<<c[i][j]<<"   ";
	for(int i=1;i<n;i++){
		int sum=0;
		for(int j=i;j>=1;j--){
			sum+=c[j][i];
//			cout<<sum<<"   ";
			if(sum>m){
				d=max(d,i-j+1);
				break;
			}
			if(j==1)d=i;
		}
		
//		cout<<endl;
	} 
	cout<<d+1;
	return 0;
	
}
