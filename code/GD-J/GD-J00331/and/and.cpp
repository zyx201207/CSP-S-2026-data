#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int s;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[j]<a[j+1]){
				a[j]=s;
				a[j]=a[j+1];
				a[j+1]=s;
			}
		}
	}
	cout<<a[0]<<" "<<a[1];
	int x=a[0];
	for(int i=1;i<m;i++){
		x=x&a[i];
	}
	cout<<x;
	return 0;
} 
