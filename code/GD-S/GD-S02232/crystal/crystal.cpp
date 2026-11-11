#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long n,m,a[N],b[N],c[N],ans = 1;

//1234นýมห
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+n+1);
	a[1] = 1,b[1] = 0;
	for(int i = 2;i<=n;i++){
		int sum = 0;
		for(int j = a[i-1]+1;j>=1;j--){
			b[i] = b[i-1]+(j-1)*(c[i]-c[i-1])-sum;
			a[i] = j;
			if(b[i]<=m){
				break;
			}
			sum+=c[i-1]-c[i-j+1];
		}
		ans = max(a[i],ans);
	}
	cout<<ans;
	return 0;
}

