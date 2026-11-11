#include<bits/stdc++.h>
using namespace std;
int n,m;
int sum=0;
const int N=2e5+5;
int a[N],b[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum=max(a[i]&a[j],sum);
		}
	}
	cout<<sum;
	return 0;
}
              