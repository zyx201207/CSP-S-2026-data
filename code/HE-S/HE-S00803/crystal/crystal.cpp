#include<bits/stdc++.h> 
using namespace std;

const int N=1010;
long long v;
int n, m, ans, a[N];
int main(){
	freopen("abc.in", "r", stdin);
	freopen("abc.out", "w", stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		for(int j=0; j<=m; j++){
			cin>>a[i];
			a[i]=i;
			cout<<" "<<endl;
		}
	}
	return 0;
}
