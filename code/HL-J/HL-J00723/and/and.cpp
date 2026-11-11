#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int b[n+1]={0};
	for(int i=1;i<=n-m+1;i++){
		for(int j=0;j<m;j++){
			if(j==0){
				b[i]=a[i];
			}
			else{
				b[i]=b[i]&a[j+i];
			}
		}
	}
	sort(b+1,b+1+n);
	cout<<b[n];
	return 0;
}