//GZ-J00580 ·½å«Ïö 
#include<iostream>
#include<algorithm>
using namespace std;

const int N=200000;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int len = n/2;
	cout<<a[len];
	return 0;
}
