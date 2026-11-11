#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],x[200005],j=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			x[j]=a[i];
			j++;
		}
	}
	if(x[1]!=0){
		long long mx=x[1];
		for(long long i=2;i<=j;i++){
			mx=max(mx,x[i]);
		}
		cout<<mx;
		return 0;
	}
	else{
		long long mn=1e9;
		long long mn1,mn2;
		for(long long i=1;i<n;i++){
			if(mn>a[i+1]-a[i]){
				mn=a[i+1]-a[i];
			}
		}
		cout<<mn;
	}
	return 0;
}
