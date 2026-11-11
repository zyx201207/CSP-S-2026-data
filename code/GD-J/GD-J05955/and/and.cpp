#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int max=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]&a[j] > max) max=a[i]&a[j];
		}
	}
	cout<<max;
	return 0;
} 
