#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200001];
long long b[200001];
long long c[200001];
int main(){	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
		if(m==1){
			sort(a+1,a+n+1);
			cout<<a[n];
			return 0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				c[i]=a[i]&a[j];
			}
		}
		
		sort(c+1,c+n+1);
		cout<<c[n];
		return 0;
}
