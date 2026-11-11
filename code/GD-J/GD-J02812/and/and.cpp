#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2e5+10;
LL a[N],sum;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	sum=a[1];
	sort(a+1,a+1+n,greater<int>());
	sum=a[1];
	for(int i=2;i<=m;i++){
	//	cout<<a[i]<<endl;
		sum=sum&a[i];
	}

	cout<<sum;
	return 0;
}
