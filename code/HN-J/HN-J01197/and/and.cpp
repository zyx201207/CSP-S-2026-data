#include<iostream>
using namespace std;
long long n,m,a[100001000];
void it(){
	cin>>n>>m;
	long long mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	cout<<mx;
}
int main(){
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	it();
	return 0;
}
