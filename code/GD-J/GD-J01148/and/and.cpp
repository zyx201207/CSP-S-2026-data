#include<bits/stdc++.h>
using namespace std;
int a[200000];
int sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int b=a[n-1];
	for(int i=n-2;i>=0;i--){
		if(b&a[i]>=min(a[i],b)&&sum<m){
			b&=a[i];
			sum++;
		}
	}
	cout<<b;
	return 0;
}
