#include<bits/stdc++.h>
#define st first
#define nd second
#define inf int(1e9+1)
#define INF int(1E18+1)
using namespace std;
typedef long long L;
typedef unsigned long long UL;
int a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,t,big=-1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,[](int x,int y){
		return x>y;
	});
	for(int i=0;i<=n-m;i++){
		t=a[i];
		for(int j=1;j<m;j++){
			t&=a[i+j];
		}
		big=max(big,t);
	}
	cout<<big;
	return 0;
}
