#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	int a[300010]={0};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int t;
			if(a[i]<a[j]){
				a[i]=t;
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	//for(int i=1;i<=n;i++){
	//	cout<<a[i]<<' ';
	//}
	cout<<a[m];
	return 0;
} 
