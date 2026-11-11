#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	cout<<a[n];
	return 0;
}
