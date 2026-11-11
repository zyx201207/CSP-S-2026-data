#include <bits/stdc++.h>
using namespace std;
long long n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	long long a[n+5]={0},maxx=-1;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			if (a[i]&a[j]>maxx){
				maxx=a[i]&a[j];
			}
		}
	}cout << maxx << endl;
	return 0;
}
