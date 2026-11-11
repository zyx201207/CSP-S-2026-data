#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long a[10005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			if(1<=i<=n){
				a[i]=2*k*i-1;
				cout<<a[i];
				break;
			}
			else if(n==2*k){
				a[i]=i-1;
				cout<<a[i];
				break;
			}
		}
	}
	return 0;
}
