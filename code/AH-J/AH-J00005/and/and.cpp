#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[200005],b[200005];
bool flag=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int sum=a[n];
	for(int i=n;i>=n-m+1;i--){
		sum&=a[i];
	}
	cout<<sum;
}
