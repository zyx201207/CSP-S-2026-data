#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],c=1,p;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	p=a[n];
	for(int i=n-1;i>=1;i--){
		if(c==m){
			break;
		}
		p=p&a[i];
		c++;
	}
	cout<<p;
	return 0;
}
