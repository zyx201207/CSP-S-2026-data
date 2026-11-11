#include<bits/stdc++.h>
using namespace std;
long long a[10000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	for(int i=1;i<=m;i++){
			for(int j=n;j>i;j--){
				if(a[j]>a[i]){
					swap(a[j],a[i]);
				}
	}
}	
	int q=a[1];
	for(int i=2;i<=m;i++){
		q=(q&a[i]);
	}
	cout<<q;
	return 0;
}
