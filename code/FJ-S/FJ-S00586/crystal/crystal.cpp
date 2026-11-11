#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=6e5+999;
int n,m;
int a[N],b[N];
int rans=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1,us=0;
	for(int i=2;i<=n;i++){
		while((i-l)*(a[i]-a[i-1])+us>m){
			us-=a[i-1]-a[l];
			l++;
		}
		us=(i-l)*(a[i]-a[i-1])+us;
//		cout<<i<<" "<<l<<" "<<us<<"\n";
		rans=max(rans,i-l+1);
	}
	cout<<rans;
	return 0;
} 
