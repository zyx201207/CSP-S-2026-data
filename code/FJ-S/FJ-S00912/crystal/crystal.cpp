#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a[100];
	cin>>n>>m;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<i;j++){
			if(a[j]>a[j+1]){
				a[j]=a[j+1];
			}
				cout<<a[j];
		}
	}
	return 0;
}