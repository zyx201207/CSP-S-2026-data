#include <bits/stdc++.h> 
using namespace std;
const int N=2e5+1;
int a[N];
int main (){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >>n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}sort(a+1,a+1+n,greater<int>());
	int ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}cout <<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
