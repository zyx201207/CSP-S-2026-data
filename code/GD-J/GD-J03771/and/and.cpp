#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005],b[200005];
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=0;i<n;i++){
		for (int j=n-1;j>i;j--){
			if(a[j-1]<a[j]){
				int temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
		}
		b[i]=a[i];
	}
	int max=a[0]&a[1];
	for (int i=3;i<=m;i++){
		max=max&a[i-1];
	}
	cout<<max;
	return 0;
}
