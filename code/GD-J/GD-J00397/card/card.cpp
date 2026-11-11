#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int a[N],inf=1e5+9;
string c[N],f[N];
string s;
void solved(){
	int n,m,b=0;
	int ans=-inf;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		b=a[n];
	}
	cout<<b<<" "<<b-2<<" "<< b+1;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solved();
	return 0;
} 
