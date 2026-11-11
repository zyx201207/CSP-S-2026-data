#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N]; 

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int ma=INT_MIN; 
	for(int i=1;i<=n;i++){
		cin>>a[i];

	}
	sort(a+1,a+n+1);

	cout<<a[n-m+1];
	return 0;
}
