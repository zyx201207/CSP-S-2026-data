#include<bits/stdc++.h>
using namespace std;
int n,m,a[200050];
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=1;j<=n;j++){
			if(a[j-1]<a[j]){
				swap(a[j-1],a[j]);
			}
		}
	}
	cout<<a[m-1];
	return 0;
}
