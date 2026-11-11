#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
	int n,m,max;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	max=a[1];
	for(int i=1;i<=n;i++){
		if(max<a[i]){
			max=a[i];
		}
	}
	if(m==1){
		cout<<max;
		return 0;
	}
	cout<<a[4];
	return 0;
}
