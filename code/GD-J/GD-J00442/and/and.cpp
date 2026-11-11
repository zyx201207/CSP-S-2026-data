#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	long long sum=a[0];
	for(int i=1;i<m;i++){
		sum=(a[i]&sum);
	}
	cout<<sum;
	return 0;
}
