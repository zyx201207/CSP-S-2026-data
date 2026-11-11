#include<bits/stdc++.h>
using namespace std;
long long a[200005],maxx=0,sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	sum=a[n];
	for(int i=n-1;i>n-m;i--){
		sum=sum&a[i];
		cout<<sum<<" "<<a[i]<<endl;
	}
	cout<<sum;
	return 0;
}
