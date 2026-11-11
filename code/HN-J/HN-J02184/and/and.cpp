#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[100001],max=-1,b[100001],h=0;
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=0;i<m-1;i++){
		for (int j=0;j<n;j++){
			for (int k=0;k<n;k++){
				b[k]=a[j]&a[k];
				h++;
			}
		}
		for (int j=0;j<h;j++){
			a[j]=b[j];
		}
	}
	for (int i=0;i<h;i++){
		if (a[i]>max){
			max=a[i];
		}
	}
	cout<<max;
	return 0;
}
