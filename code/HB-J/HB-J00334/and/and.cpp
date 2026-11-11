#include <bits/stdc++.h>
using namespace std;
int a[20005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int maxn=-999999;
	for(int i=1;i<n-1;i++){
		for(int j=0;j<n-i;j++){
			if(a[j]&&a[j+1]>maxn){
				maxn=a[j]&a[j+1];
			}
		}
	}
	cout<<maxn;
	return 0;
}
