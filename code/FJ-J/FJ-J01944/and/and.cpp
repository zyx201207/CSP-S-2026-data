#include<bits/stdc++.h>
using namespace std;
long long a[100010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cout<<a[i];
		k++;
	}
	cout<<a[k];
	return 0;
} 
