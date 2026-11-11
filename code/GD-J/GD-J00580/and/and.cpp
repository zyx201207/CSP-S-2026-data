#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,k;
int a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("and1.in","r",stdin);
	//freopen("and1.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	//sort(a+1,a+1+n);
	int mx=-1e9;
	for(int i=1; i<=n; i++){
		int x=a[i];
		for(int j=i+1; j<=i+k; j++){
			x&=a[j];
		}
		mx=max(x,mx);
	}
	cout<<mx;
	return 0;
}
