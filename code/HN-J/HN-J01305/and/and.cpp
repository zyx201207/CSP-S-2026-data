#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,sum=0;
	cin>>n>>m;
	int a[200000];
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	cout<<sum/n+m;
	return 0;
}
