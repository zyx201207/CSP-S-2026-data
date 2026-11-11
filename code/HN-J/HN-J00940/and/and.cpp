#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+4];
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i]>a[i+j]){
				int q;
				q=a[i];
				a[i]=a[i+j];
				a[i+j]=q;
			}
		}
	}
	cout<<a[2];
	return 0;
}
