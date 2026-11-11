#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+5;
int n,m,x;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n>2000){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m];
	}
	if(m==1){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[1];
	}
	if(m==2){
		int mx=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i!=j&&(a[i]&a[j])>mx) mx=(a[i]&a[j]);
			}
		cout<<mx;
	}
	if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++) sum&=a[i];
		cout<<sum;
	}
	return 0;
}
