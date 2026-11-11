#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,maxn;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum=(sum&a[i]);
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n-m+1;i++){
		int sum=a[i];
		for(int j=i+1;j<=i+m-1;j++){
			sum=(sum&a[j]);
		}
		maxn=max(maxn,sum);
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
