#include<bits/stdc++.h>
using namespace std;
const int N=500010;
const int M=500010;
int a[N],s[N];

int main(){
	int n,m;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int ans=1;
	for(int i=0;i<n;i++){
		int sum=1;
		for(int j=0;j<m;j++){
			sum=a[n-j-1-i]&sum;
		}
	}
	return 0;
	}
