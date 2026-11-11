#include <bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m;
long long a[N],pre[N];
bool check(int num){
	int p=num;
	while(p<=n){
		if((pre[p]-pre[p-num]+m)/num>=a[p]){
			return 1;
		}
		p++;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		int mid=l+(r-l+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
} 
