#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=-1;
int a[200005],b[200005];
int andd(int a,int b){
	int c=a&b;
	return c;
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=1;i<n;i++){
			ans=andd(ans,a[i+1]);
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=1;i<m;i++){
		ans=andd(ans,a[i+1]);
	}
	cout<<ans;
	return 0;
}
