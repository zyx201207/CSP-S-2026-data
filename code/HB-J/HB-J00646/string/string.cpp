#include <bits/stdc++.h>
using namespace std;
long long len=0,n,ans=0;
struct node{
	long long x;
	char y;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	long long l=1,r=n;
	while(l<r){
		if(a[l].x>a[r].x&&a[r].y==a[l].y){
			a[l].x-=a[r].x;
			r--;
		}
		if(a[l].x<a[r].x&&a[r].y==a[l].y){
			a[r].x-=a[l].x;
			l++;
		}
		if(a[l].x<a[r].x&&a[r].y!=a[l].y){
			a[r].x-=a[l].x;
			ans+=a[l].x;
			l++;
		}
		if(a[l].x>a[r].x&&a[r].y!=a[l].y){
			a[l].x-=a[r].x;
			ans+=a[r].x;
			r--;
		}
		if(a[l].x==a[r].x&&a[r].y!=a[l].y){
			ans+=a[r].x;
			r--;
			l++;
		}
		if(a[l].x==a[r].x&&a[r].y==a[l].y){
			r--;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
