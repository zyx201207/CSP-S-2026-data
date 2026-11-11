#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int n,m,a[N],maxn;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxn){
			maxn=a[i];
		}
	}
	cout<<maxn;
	return 0;
}

