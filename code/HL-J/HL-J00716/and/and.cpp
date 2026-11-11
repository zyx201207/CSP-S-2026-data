#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,max1;
long long a[200005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n-m;i++){
		ans=a[i];
		for(int j=i+1;j<=i+m-1;j++){
			ans&=a[j];
		}
		max1=max(ans,max1);
	}
	cout<<max1;
	return 0;
}

