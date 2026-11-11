#include <iostream>
using namespace std; 
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,h=1;
	long long a[100000];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int q=1;
		for(int j=1;j<=n;j++){
			if(a[i]>=a[j]&&a[i]-a[j]<=m){
				q++;
				m=m-a[i]+a[j];
			}	
		}
		if(q>h){
			h=q;
		}
	}
	cout<<h;
	return 0;
}
