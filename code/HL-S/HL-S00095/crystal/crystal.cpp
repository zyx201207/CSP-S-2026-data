#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int a[N];
long long n,m,i;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int p = 1;p<=n;p++) cin>>a[p];
	int p = a[2]-a[1];
	while(i*(i+1)/2*p <= m) i++;
	cout<<i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
