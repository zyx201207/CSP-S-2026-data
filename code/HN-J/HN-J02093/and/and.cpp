#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,maxn=100000,a[N],b[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		
	}
	sort(a+1,a+1+n,cmp);
	
	for(int i=1;i<=n;i++){
		if(i<=m){
			if(maxn>a[i]){
				maxn=a[i];
			}
		}
	}
	cout << maxn;
	return 0;
}
