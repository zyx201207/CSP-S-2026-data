#include<bits/stdc++.h>
using namespace std;
const int M=1e6;
int n,m;
long long ans=0;
long long a[M];
void init();
void work();
void print();
void init(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
}
void work(){
	sort(a,a+n);
	ans=a[n-1];
	for(int i=n-2;i>=n-m;i--) ans=(ans&a[i]);
}
void print(){
	cout<<ans;
}
int main(){
	init();
	work();
	print();
	return 0;
} 
