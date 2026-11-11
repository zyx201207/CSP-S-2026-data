#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100010],b[100010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=n;i>=m;i--) b[i]=a[i];
	int cnt=b[n];
	for(int i=n;i>=m;i--){
		cnt=cnt&b[i];
	}
	cout<<cnt;
	return 0;
}                      
