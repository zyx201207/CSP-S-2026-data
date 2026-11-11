//GZ-J00195 贵阳市南明区李端棻中学 周熙沅 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	int a[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int maxx[m+5];
	maxx[1]=a[0];
	for(int i=1;i<n;i++){
		if(maxx[i]<=a[i]){
			for(int j=m;j>=2;j--){
				maxx[j]=maxx[j-1];
			}
			maxx[1]=a[i];
		}
	}
	x=maxx[1];
	for(int i=2;i<m;i++){
		x=x&maxx[i];
	}
	cout<<x;
	return 0;
}
