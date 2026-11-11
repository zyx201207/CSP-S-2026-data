#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,m,m1;
long long a[N];
long long maxx = -1;
void rp(int h,int m,int an){
	for(int i = h;i <= n;i++){
		if(m==m1){
			an = a[i];
			rp(i+1,m-1,a[i]);
		}
		if(m==1){
			long long maxn = an;
			maxn&=a[i];
			maxx = max(maxx,maxn);
		}else{
			rp(i+1,m-1,an&a[i]);
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	m1 = m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	rp(1,m,0);
	cout<<maxx;
	return 0;
}
